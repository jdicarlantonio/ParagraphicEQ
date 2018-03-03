/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
static String bandToString(int bandValue)
{
    switch(bandValue)
    {
        case 0:
        {
            return "Low";
            break;
        }
        case 1:
        {
            return "Low-Mid";
            break;
        }
        case 2:
        {
            return "High-Mid";
            break;
        }
        case 3:
        {
            return "High";
            break;
        }
    }
}

static String bypassText(float value)
{
    return (value != 0) ? "Bypassed" : "Enabled";
}

ParagraphicEqAudioProcessor::ParagraphicEqAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
     , parameters (*this, &undoManager)
#endif
{
    parameters.createAndAddParameter(
        "bypass",
        "Bypass",
        String(),
        NormalisableRange<float> (0, 1, 1),
        0,
        bypassText,
        nullptr
    );

    parameters.createAndAddParameter(
        freqParameterIDs[FrequencyRange::LOW],
        "Low Frequency",
        String(),
        NormalisableRange<float> (0.0f, 400.0f, 0.01f),
        40.0f,
        nullptr,
        nullptr
    );
    parameters.createAndAddParameter(
        freqParameterIDs[FrequencyRange::LOW_MID],
        "Low-Mid Frequency",
        String(),
        NormalisableRange<float> (200.0f, 1000.0f, 0.01f),
        400.0f,
        nullptr,
        nullptr
    );
    parameters.createAndAddParameter(
        freqParameterIDs[FrequencyRange::HIGH_MID],
        "High-Mid Frequency",
        String(),
        NormalisableRange<float> (800.0f, 10000.0f, 0.01f),
        1800.0f,
        nullptr,
        nullptr
    );
    parameters.createAndAddParameter(
        freqParameterIDs[FrequencyRange::HIGH],
        "High Frequency",
        String(),
        NormalisableRange<float> (3500.0f, 22000.0f, 0.01f),
        8000.0f,
        nullptr,
        nullptr
    );

    // Gain Parameters
    for(int i = 0; i < NUM_BANDS; ++i)
    {
        parameters.createAndAddParameter(
            gainParameterIDs[i],
            bandToString(i) + " Gain in dB",
            String(),
            NormalisableRange<float> (-18.0, 18.0, 0.01f),
            0.0f,
            nullptr,
            nullptr
        );   
    }
    
    parameters.addParameterListener("bypass", this);
    for(int i = 0; i < NUM_BANDS; ++i)
    {
        parameters.addParameterListener(freqParameterIDs[i], this);
        parameters.addParameterListener(gainParameterIDs[i], this);
    }
    
    paramChanged = true;
}

ParagraphicEqAudioProcessor::~ParagraphicEqAudioProcessor()
{
}

//==============================================================================
const String ParagraphicEqAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ParagraphicEqAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool ParagraphicEqAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool ParagraphicEqAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double ParagraphicEqAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ParagraphicEqAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int ParagraphicEqAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ParagraphicEqAudioProcessor::setCurrentProgram (int index)
{
}

const String ParagraphicEqAudioProcessor::getProgramName (int index)
{
    return {};
}

void ParagraphicEqAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void ParagraphicEqAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void ParagraphicEqAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ParagraphicEqAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void ParagraphicEqAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
}

//==============================================================================
bool ParagraphicEqAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* ParagraphicEqAudioProcessor::createEditor()
{
    return new ParagraphicEqAudioProcessorEditor (*this);
}

//==============================================================================
void ParagraphicEqAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void ParagraphicEqAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ParagraphicEqAudioProcessor();
}

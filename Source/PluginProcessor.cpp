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
		default:
		{
			return "No Range";
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
     , Q {0.71f}
     , dBGainMagnitude {0.0f}
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

    // Q factor is proportional to Gain in dB 
    parameters.createAndAddParameter(
        "qProportion",
        "Proportion Constant for Q - Gain Relationship",
        String(),
        NormalisableRange<float> (0.001f, 1.0f, 0.001f),
        0.250f,
        nullptr,
        nullptr
    );
    proportionConstant = 0.25f;

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
    parameters.addParameterListener("qProportion", this);
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
    for(int i = 0; i < NUM_BANDS; ++i)
    {
        leftFilters[i].reset();
        rightFilters[i].reset();
    }
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

    if(paramChanged)
    {
        // calculate some coefficients
        proportionConstant = *parameters.getRawParameterValue("qProportion");
        for(int i = 0; i < NUM_BANDS; ++i)
        {
            dBGainMagnitude = *parameters.getRawParameterValue(gainParameterIDs[i]);
			dBGainMagnitude = (dBGainMagnitude < 0) ? -dBGainMagnitude : dBGainMagnitude;

            Q = (dBGainMagnitude == 0) ? Q : (dBGainMagnitude * proportionConstant);

            leftFilters[i].calculateCoefficients(
                getSampleRate(),
                *parameters.getRawParameterValue(freqParameterIDs[i]),
				*parameters.getRawParameterValue(gainParameterIDs[i]),
                Q
            );
            rightFilters[i].calculateCoefficients(
                getSampleRate(),
                *parameters.getRawParameterValue(freqParameterIDs[i]),
				*parameters.getRawParameterValue(gainParameterIDs[i]),
                Q
            );
        }
    }

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // check if bypassed
    if(*parameters.getRawParameterValue("bypass") == 0.0f)
    {
        // we aren't bypassed in here
        float* leftChannelData = buffer.getWritePointer(0);
        float* rightChannelData = buffer.getWritePointer(1);

        for(int i = 0; i < NUM_BANDS; ++i)
        {
            leftFilters[i].process(leftChannelData, buffer.getNumSamples());
            rightFilters[i].process(rightChannelData, buffer.getNumSamples());
        }
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

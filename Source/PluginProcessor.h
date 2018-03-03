/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "DSP/BiQuad.h"


//==============================================================================
/**
*/
static constexpr int NUM_BANDS = 4;

enum FrequencyRange
{
    LOW = 0,
    LOW_MID,
    HIGH_MID,
    HIGH
};

class ParagraphicEqAudioProcessor  
    : public AudioProcessor
    , public AudioProcessorValueTreeState::Listener
{
public:
    //==============================================================================
    ParagraphicEqAudioProcessor();
    ~ParagraphicEqAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    const std::array<String, NUM_BANDS> freqParameterIDs = {
        "lowFreq",
        "lowMidFreq",
        "highMidFreq",
        "highFreq"
    };

    const std::array<String, NUM_BANDS> gainParameterIDs = {
        "lowGain",
        "lowMidGain",
        "highMidGain",
        "highGain"
    };
    
    AudioProcessorValueTreeState& getState()
    {
        return parameters;
    }
    
    void parameterChanged(const String& parameterID, float newValue)
    {
        paramChanged = true;
    }

private:
    bool paramChanged;
    AudioProcessorValueTreeState parameters;
    UndoManager undoManager;

    std::array<BiQuad, NUM_BANDS> leftFilters;
    std::array<BiQuad, NUM_BANDS> rightFilters;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParagraphicEqAudioProcessor)
};

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    Marquee hLeft {"Here is some scrolling text to the left"};
    Marquee hRight {"Here is some scrolling text to the right going faster!", Marquee::ScrollDirection::HorizonalRight, 2, false};
    
    Marquee mPausing{"This one pauses when the text is done", Marquee::ScrollDirection::HorizonalLeft, 1, true};
    
    Marquee vUp {"This on goes up...", Marquee::ScrollDirection::VerticalUp, 1, false};
    Marquee vDown {"This on goes down...", Marquee::ScrollDirection::VerticalDown, 1, false};
    
    std::vector<Marquee *> marquees = {
        &hLeft,
        &hRight,
        &mPausing,
        &vUp,
        &vDown
    };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

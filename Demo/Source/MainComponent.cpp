#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (300, 300);
    
    for (auto m : marquees) {
        m->setSize(120, 30);
        addAndMakeVisible(m);
    }
    
    mPausing.setPauseTime(50);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    int y = 10;
    for (auto m : marquees) {
        m->setCentrePosition(100, y);
        y += 50;
    }
}

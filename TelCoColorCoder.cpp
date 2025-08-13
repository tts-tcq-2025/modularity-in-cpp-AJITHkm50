// TelCoColorCoder.cpp
#include "TelCoColorCoder.h" // Include its own header
#include <stdexcept>         // For std::out_of_range or similar error handling

namespace TelCoColorCoder
{
    // Definitions of the color names and counts
    const char* MajorColorNames[] = {
        "White", "Red", "Black", "Yellow", "Violet"
    };
    const int numberOfMajorColors =
        sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

    const char* MinorColorNames[] = {
        "Blue", "Orange", "Green", "Brown", "Slate"
    };
    const int numberOfMinorColors =
        sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    // ColorPair Class Implementation
    ColorPair::ColorPair(MajorColor major, MinorColor minor) :
        majorColor(major), minorColor(minor)
    {}

    MajorColor ColorPair::getMajor() const {
        return majorColor;
    }

    MinorColor ColorPair::getMinor() const {
        return minorColor;
    }

    std::string ColorPair::ToString() const {
        std::string colorPairStr = MajorColorNames[majorColor];
        colorPairStr += " ";
        colorPairStr += MinorColorNames[minorColor];
        return colorPairStr;
    }

    // Free functions for color-number conversion
    ColorPair GetColorFromPairNumber(int pairNumber) {
        // Validate input pairNumber
        if (pairNumber < 1 || pairNumber > GetMaxPairNumber()) {
            throw std::out_of_range("Pair number out of range: " + std::to_string(pairNumber));
        }

        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor =
            static_cast<MajorColor>(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            static_cast<MinorColor>(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        // Basic validation for major and minor enums
        if (major < WHITE || major >= numberOfMajorColors ||
            minor < BLUE || minor >= numberOfMinorColors)
        {
            throw std::out_of_range("Invalid major or minor color enum value.");
        }
        return major * numberOfMinorColors + minor + 1;
    }

    int GetMaxPairNumber() {
        return numberOfMajorColors * numberOfMinorColors;
    }

} // namespace TelCoColorCoder

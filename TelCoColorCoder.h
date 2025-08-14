#include "TelCoColorCoder.h"
#include <stdexcept>

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

    // Converts pair number to ColorPair; throws if out of range
    ColorPair GetColorFromPairNumber(int pairNumber) {
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

    // Converts ColorPair to pair number; throws if enums are invalid
    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
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

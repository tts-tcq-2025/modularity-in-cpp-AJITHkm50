#include "TelCoColorCoder.h" // Include its own header for declarations
#include <string>            // Already included, but good practice for .cpp files

namespace TelCoColorCoder
{
    // Definitions of the color name std::arrays.
    // These match the declarations in the header.
    namespace detail {
        const std::array<const char*, 5> kMajorColorNames = {
            "White", "Red", "Black", "Yellow", "Violet"
        };
        const std::array<const char*, 5> kMinorColorNames = {
            "Blue", "Orange", "Green", "Brown", "Slate"
        };
    }

    // ColorPair class implementations.
    ColorPair::ColorPair(MajorColor major, MinorColor minor) noexcept
        : majorColor_(major), minorColor_(minor) {}

    MajorColor ColorPair::getMajor() const noexcept {
        return majorColor_;
    }

    MinorColor ColorPair::getMinor() const noexcept {
        return minorColor_;
    }

    std::string ColorPair::ToString() const {
        // Explicitly cast enum class to int to index std::array.
        return std::string(detail::kMajorColorNames[static_cast<int>(majorColor_)]) +
               " " +
               std::string(detail::kMinorColorNames[static_cast<int>(minorColor_)]);
    }

    // Converts a pair number to a ColorPair.
    ColorPair GetColorFromPairNumber(int pairNumber) {
        // Validate input pairNumber against the maximum possible pairs.
        if (pairNumber < 1 || pairNumber > GetMaxPairNumber()) {
            throw ColorCodeError("Pair number " + std::to_string(pairNumber) + " is out of valid range.");
        }

        const int zeroBasedPairNumber = pairNumber - 1;

        // Calculation relies on integer division and modulo.
        // Explicitly cast to enum class types after calculation.
        MajorColor majorColor = static_cast<MajorColor>(zeroBasedPairNumber / detail::kNumberOfMinorColors);
        MinorColor minorColor = static_cast<MinorColor>(zeroBasedPairNumber % detail::kNumberOfMinorColors);

        return ColorPair(majorColor, minorColor);
    }

    // Converts MajorColor and MinorColor to a pair number.
    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        // Using static_cast<int>(enum_class) for calculations.
        const int majorIdx = static_cast<int>(major);
        const int minorIdx = static_cast<int>(minor);

        // Input validation for enum values. While enum class provides type safety,
        // it's possible to cast invalid integers to enum values.
        if (majorIdx < 0 || majorIdx >= static_cast<int>(detail::kNumberOfMajorColors) ||
            minorIdx < 0 || minorIdx >= static_cast<int>(detail::kNumberOfMinorColors)) {
            throw ColorCodeError("Invalid major or minor color enum value provided.");
        }

        // Formula for 1-based pair number.
        return (majorIdx * static_cast<int>(detail::kNumberOfMinorColors)) + minorIdx + 1;
    }
}

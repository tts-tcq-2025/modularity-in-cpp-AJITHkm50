#ifndef TELCOCOLORCODER_H
#define TELCOCOLORCODER_H

#include <string>  // For std::string
#include <array>   // For std::array
#include <stdexcept> // For std::runtime_error base

namespace TelCoColorCoder
{
    // Custom exception for color code related errors.
    class ColorCodeError : public std::runtime_error {
    public:
        explicit ColorCodeError(const std::string& message)
            : std::runtime_error("TelCoColorCoder Error: " + message) {}
    };

    // Enum classes for strong typing, preventing implicit conversions.
    enum class MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
    enum class MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

    // Constants for the number of colors, declared as constexpr.
    // Definitions are in the .cpp file, leveraging std::array's size.
    // Access as TelCoColorCoder::detail::kNumberOfMajorColors
    namespace detail {
        extern const std::array<const char*, 5> kMajorColorNames;
        extern const std::array<const char*, 5> kMinorColorNames;

        // Using std::array::size() for compile-time constant size.
        // These are effectively global constants within the namespace.
        constexpr std::size_t kNumberOfMajorColors = kMajorColorNames.size();
        constexpr std::size_t kNumberOfMinorColors = kMinorColorNames.size();
    }

    // Class to represent a color pair.
    class ColorPair {
    private:
        MajorColor majorColor_; // Suffix '_' for member variables is a common convention.
        MinorColor minorColor_;

    public:
        ColorPair(MajorColor major, MinorColor minor) noexcept;

        [[nodiscard]] MajorColor getMajor() const noexcept;
        [[nodiscard]] MinorColor getMinor() const noexcept;

        // Returns a string representation (e.g., "White Blue").
        [[nodiscard]] std::string ToString() const;
    };

    // Converts a 1-based pair number to a ColorPair.
    // Throws ColorCodeError if pairNumber is out of range.
    [[nodiscard]] ColorPair GetColorFromPairNumber(int pairNumber);

    // Converts MajorColor and MinorColor to a 1-based pair number.
    // Throws ColorCodeError if enum values are invalid (should ideally not happen with enum class).
    [[nodiscard]] int GetPairNumberFromColor(MajorColor major, MinorColor minor);

    // Returns the total maximum number of color pairs.
    [[nodiscard]] constexpr int GetMaxPairNumber() noexcept {
        return static_cast<int>(detail::kNumberOfMajorColors * detail::kNumberOfMinorColors);
    }
}
#endif 

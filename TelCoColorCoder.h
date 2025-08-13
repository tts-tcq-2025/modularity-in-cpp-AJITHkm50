// TelCoColorCoder.h
#ifndef TEL_CO_COLOR_CODER_H
#define TEL_CO_COLOR_CODER_H

#include <string> // Required for std::string
#include <vector> // Required for storing color names

namespace TelCoColorCoder
{
    // Enum for Major Colors
    enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};

    // Enum for Minor Colors
    enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

    // Arrays to store human-readable names for Major and Minor Colors
    // extern is used here because the actual definition (storage) will be in the .cpp file
    extern const char* MajorColorNames[];
    extern const int numberOfMajorColors; // Extern as definition is in .cpp

    extern const char* MinorColorNames[];
    extern const int numberOfMinorColors; // Extern as definition is in .cpp

    // Class to represent a color pair
    class ColorPair {
    private:
        MajorColor majorColor;
        MinorColor minorColor;

    public:
        // Constructor
        ColorPair(MajorColor major, MinorColor minor);

        // Getters for major and minor colors
        MajorColor getMajor() const; // const correctness: doesn't modify the object
        MinorColor getMinor() const; // const correctness: doesn't modify the object

        // Returns a string representation of the color pair
        std::string ToString() const; // const correctness
    };

    // Function to get a ColorPair from its pair number
    ColorPair GetColorFromPairNumber(int pairNumber);

    // Function to get the pair number from a ColorPair
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);

    // Function to get total number of unique color pairs
    int GetMaxPairNumber();

} // namespace TelCoColorCoder

#endif // TEL_CO_COLOR_CODER_H

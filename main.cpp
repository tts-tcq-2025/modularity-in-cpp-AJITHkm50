// main.cpp
#include <iostream>
#include <assert.h> // For assert
#include <stdexcept> // For std::out_of_range

#include "TelCoColorCoder.h" // Core logic
#include "ColorManual.h"     // New feature: print manual

// Test functions (moved out of namespace for simplicity in main, or could be in a Test namespace)
void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    try {
        TelCoColorCoder::ColorPair colorPair =
            TelCoColorCoder::GetColorFromPairNumber(pairNumber);
        std::cout << "Test: Pair Number " << pairNumber << " -> " << colorPair.ToString() << std::endl;
        assert(colorPair.getMajor() == expectedMajor);
        assert(colorPair.getMinor() == expectedMinor);
    } catch (const std::out_of_range& e) {
        std::cerr << "Test failed for pair " << pairNumber << ": " << e.what() << std::endl;
        assert(false); // Force assertion failure for invalid pair numbers if they were expected to pass
    }
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    try {
        int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
        std::cout << "Test: " << TelCoColorCoder::MajorColorNames[major] << " "
                  << TelCoColorCoder::MinorColorNames[minor] << " -> Pair Number " << pairNumber << std::endl;
        assert(pairNumber == expectedPairNumber);
    } catch (const std::out_of_range& e) {
        std::cerr << "Test failed for color pair: " << e.what() << std::endl;
        assert(false); // Force assertion failure for invalid colors if they were expected to pass
    }
}

int main() {
    std::cout << "Running TelCo Color Coder Tests..." << std::endl;

    // Test cases for number to pair conversion
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);
    testNumberToPair(1, TelCoColorCoder::WHITE, TelCoColorCoder::BLUE);
    testNumberToPair(25, TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE);

    // Test cases for pair to number conversion
    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
    testPairToNumber(TelCoColorCoder::WHITE, TelCoColorCoder::BLUE, 1);

    // Test boundary conditions
    testNumberToPair(TelCoColorCoder::GetMaxPairNumber(), TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE);
    testPairToNumber(TelCoColorCoder::WHITE, TelCoColorCoder::BLUE, 1);


    std::cout << "\nAll TelCo Color Coder Tests Passed!" << std::endl;

    // New Feature: Print the color code manual
    std::cout << "\nGenerating Color Code Manual..." << std::endl;
    TelCoColorCoder::ColorManual::PrintColorCodeManual(std::cout);
    std::cout << "Color Code Manual Generated." << std::endl;

    return 0;
}

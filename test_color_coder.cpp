#include "test_color_coder.h"
#include <iostream>
#include <assert.h>
#include <stdexcept>
using namespace TelCoColorCoder;

static void testNumberToPair(int pairNumber, MajorColor expectedMajor, MinorColor expectedMinor) {
    try {
        ColorPair colorPair = GetColorFromPairNumber(pairNumber);
        std::cout << "Test: Pair Number " << pairNumber << " -> " << colorPair.ToString() << std::endl;
        assert(colorPair.getMajor() == expectedMajor);
        assert(colorPair.getMinor() == expectedMinor);
    } catch (const std::out_of_range& e) {
        std::cerr << "Test failed for pair " << pairNumber << ": " << e.what() << std::endl;
        assert(false);
    }
}

static void testPairToNumber(MajorColor major, MinorColor minor, int expectedPairNumber) {
    try {
        int pairNumber = GetPairNumberFromColor(major, minor);
        std::cout << "Test: " << MajorColorNames[static_cast<int>(major)] << " " << MinorColorNames[static_cast<int>(minor)] << " -> Pair Number " << pairNumber << std::endl;
        assert(pairNumber == expectedPairNumber);
    } catch (const std::out_of_range& e) {
        std::cerr << "Test failed for color pair: " << e.what() << std::endl;
        assert(false);
    }
}

void runColorCoderTests() {
    // Test cases for number to pair conversion
    testNumberToPair(4, TelCo::Major::WHITE, TelCo::Minor::BROWN);
    testNumberToPair(5, TelCo::Major::WHITE, TelCo::Minor::SLATE);
    testNumberToPair(1, TelCo::Major::WHITE, TelCo::Minor::BLUE);
    testNumberToPair(25, TelCo::Major::VIOLET, TelCo::Minor::SLATE);

    // Test cases for pair to number conversion
    testPairToNumber(TelCo::Major::BLACK, TelCo::Minor::ORANGE, 12);
    testPairToNumber(TelCo::Major::VIOLET, TelCo::Minor::SLATE, 25);
    testPairToNumber(TelCo::Major::WHITE, TelCo::Minor::BLUE, 1);

    // Test boundary conditions
    testNumberToPair(GetMaxPairNumber(), TelCo::Major::VIOLET, TelCo::Minor::SLATE);
    testPairToNumber(TelCo::Major::WHITE, TelCo::Minor::BLUE, 1);
    std::cout << "\nAll TelCo Color Coder Tests Passed!" << std::endl;
}

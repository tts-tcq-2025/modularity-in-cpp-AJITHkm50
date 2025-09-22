#include <iostream>
#include "test_color_coder.h"
#include "ColorManual.h"

int main() {
    std::cout << "Running TelCo Color Coder Tests..." << std::endl;
    runColorCoderTests();
    std::cout << "\nGenerating Color Code Manual..." << std::endl;
    TelCoColorCoder::ColorManual::PrintColorCodeManual(std::cout);
    std::cout << "Color Code Manual Generated." << std::endl;
    return 0;
}

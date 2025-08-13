// ColorManual.cpp
#include "ColorManual.h"
#include "TelCoColorCoder.h" // Needed for TelCoColorCoder::GetColorFromPairNumber and other constants
#include <iomanip>           // For std::setw

namespace TelCoColorCoder
{
    void ColorManual::PrintColorCodeManual(std::ostream& os)
    {
        os << "------------------------------------------" << std::endl;
        os << "          TelCo Color Code Manual         " << std::endl;
        os << "------------------------------------------" << std::endl;
        os << std::left << std::setw(8) << "Pair No."
           << std::setw(15) << "Major Color"
           << std::setw(15) << "Minor Color" << std::endl;
        os << "------------------------------------------" << std::endl;

        int maxPairNumber = GetMaxPairNumber();
        for (int i = 1; i <= maxPairNumber; ++i)
        {
            ColorPair colorPair = GetColorFromPairNumber(i);
            os << std::left << std::setw(8) << i
               << std::setw(15) << MajorColorNames[colorPair.getMajor()]
               << std::setw(15) << MinorColorNames[colorPair.getMinor()] << std::endl;
        }
        os << "------------------------------------------" << std::endl;
        os << std::endl;
    }

} // namespace TelCoColorCoder

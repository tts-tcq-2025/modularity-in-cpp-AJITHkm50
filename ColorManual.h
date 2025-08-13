// ColorManual.h
#ifndef COLOR_MANUAL_H
#define COLOR_MANUAL_H

#include <iostream> // For std::ostream

namespace TelCoColorCoder
{
    // Forward declaration to avoid circular includes if TelCoColorCoder.h wasn't already included
    // (though in this case, we need it for MajorColor, MinorColor, etc.)
    // We'll rely on TelCoColorCoder.h being included.

    // This class handles generating the color code manual.
    class ColorManual
    {
    public:
        // Prints the color code manual to the given output stream.
        // It lists all pair numbers with their corresponding major and minor colors.
        static void PrintColorCodeManual(std::ostream& os);
    };

} // namespace TelCoColorCoder

#endif // COLOR_MANUAL_H

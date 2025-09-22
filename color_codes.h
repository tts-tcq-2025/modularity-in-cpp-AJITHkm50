#ifndef COLOR_CODES_H
#define COLOR_CODES_H
#include <string> // For std::string
#include <array>  // For std::array
#include <stdexcept>// For std::out_of_range

namespace TelCo { 
enum class Major {WHITE, RED, BLACK, YELLOW, VIOLET};
enum class Minor {BLUE, ORANGE, GREEN, BROWN, SLATE};

extern const std::array<const char*, 5> MajorNames;
extern const std::array<const char*, 5> MinorNames;
constexpr size_t NumMajors = MajorNames.size(); // Use size_t
constexpr size_t NumMinors = MinorNames.size();

class ColorPair { // Represents a color combination
  Major major_; Minor minor_;
public:
  ColorPair(Major maj, Minor min) noexcept : major_(maj), minor_(min) {}
  Major getMajor() const noexcept { return major_; }
  Minor getMinor() const noexcept { return minor_; }
  std::string ToString() const { // Combine string creation
    return std::string(MajorNames[static_cast<int>(major_)]) + " " +
           std::string(MinorNames[static_cast<int>(minor_)]);
  }};
ColorPair get_color(int pairNum);
int get_pair_num(Major maj, Minor min);
constexpr int max_pairs() noexcept { return NumMajors * NumMinors; }
} 
#endif // COLOR_CODES_H

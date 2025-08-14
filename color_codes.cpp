#include "color_codes.h" // Own header
namespace TelCo { // Namespace must match header
// Definitions of color names (extern in header)
const std::array<const char*, 5> MajorNames = {
    "White", "Red", "Black", "Yellow", "Violet"
};
const std::array<const char*, 5> MinorNames = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

// Function: Get ColorPair from pair number
ColorPair get_color(int pairNum) {
  if (pairNum < 1 || pairNum > max_pairs())
    throw std::out_of_range("Invalid pair num: " + std::to_string(pairNum));
  int zero_based = pairNum - 1;
  return ColorPair(static_cast<Major>(zero_based / NumMinors),
                   static_cast<Minor>(zero_based % NumMinors));
}

// Function: Get pair number from Major and Minor colors
int get_pair_num(Major maj, Minor min) {
  int maj_idx = static_cast<int>(maj);
  int min_idx = static_cast<int>(min);
  if (maj_idx < 0 || maj_idx >= static_cast<int>(NumMajors) ||
      min_idx < 0 || min_idx >= static_cast<int>(NumMinors))
    throw std::out_of_range("Invalid color enum value.");
  return (maj_idx * static_cast<int>(NumMinors)) + min_idx + 1;
}
} // namespace TelCo

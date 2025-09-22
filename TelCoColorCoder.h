#ifndef TELCO_COLORCODER_H
#define TELCO_COLORCODER_H
#include "color_codes.h"
namespace TelCoColorCoder {
using MajorColor = TelCo::Major;
using MinorColor = TelCo::Minor;
using ColorPair = TelCo::ColorPair;
constexpr size_t NumMajors = TelCo::NumMajors;
constexpr size_t NumMinors = TelCo::NumMinors;
constexpr int GetMaxPairNumber() noexcept { return TelCo::max_pairs(); }
inline ColorPair GetColorFromPairNumber(int pairNum) { return TelCo::get_color(pairNum); }
inline int GetPairNumberFromColor(MajorColor maj, MinorColor min) { return TelCo::get_pair_num(maj, min); }
constexpr const char* const* MajorColorNames = TelCo::MajorNames.data();
constexpr const char* const* MinorColorNames = TelCo::MinorNames.data();
}
#endif // TELCO_COLORCODER_H

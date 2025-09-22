#include "manual_gen.h" // Own header
#include "color_codes.h" // Required for core logic, enums, etc.
#include <iomanip>      // For std::setw
namespace TelCo {       // Namespace must match
void print_manual(std::ostream& os) {

  os << std::left << std::setw(10) << "Pair No." << std::setw(15)
     << "Major Color" << std::setw(15) << "Minor Color" << "\n";
  for (size_t i = 0; i < NumMajors; ++i) { // Use size_t for loops
    for (size_t j = 0; j < NumMinors; ++j) {
      Major maj = static_cast<Major>(i);
      Minor min = static_cast<Minor>(j);
      os << std::left << std::setw(10) << get_pair_num(maj, min)
         << std::setw(15) << MajorNames[i] << std::setw(15) << MinorNames[j]
         << "\n";
    }
  }

}
} // namespace TelCo

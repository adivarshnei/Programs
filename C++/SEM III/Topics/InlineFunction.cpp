#include <iostream>

inline float lbsToKg(float pounds) {
   return 0.453592 * pounds;
}

int main(void) {
   std::cout << "55 lbs = " << lbsToKg(55) << " kg" << std::endl;
   return 0;
}

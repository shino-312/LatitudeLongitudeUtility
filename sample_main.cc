#include <cstdio>
#include "geo_conversion_function.h"

int main(void) {
  using namespace geoutility;

  /***********************************************************************
   * Calculate local distance from Tokyo Station to Tokyo Imeprial Palace.
   ***********************************************************************/
  const Blh tokyo_station = {
      degToRad(35.6752),   // rad
      degToRad(139.7668),  // rad
      0.0                  // meter
  };

  const Blh imperial_palace = {
      degToRad(35.6825),   // rad
      degToRad(139.7521),  // rad
      0.0                  // meter
  };

  // Calculate local distance with ENU(East, North, Up)
  const Enu dist = calcEnu(tokyo_station, imperial_palace);

  printf("From Tokyo Station to Tokyo Imperial Palace:\n");
  printf("East : %f [m]\n", dist.e);
  printf("North: %f [m]\n", dist.n);

  /***********************************************************************
   * Restore latitude/longitude from the calculated distance
   ***********************************************************************/
  const Blh imperial_palace_restored = calcBlh(tokyo_station, dist);

  printf(
      "\nLet's restore lat/lon of Imperial Palace.\n"
      "The same values should be obtained.\n");

  printf("Latitude : %f(raw) vs %f(restored)\n", radToDeg(imperial_palace.lat),
         radToDeg(imperial_palace_restored.lat));

  printf("Longitude: %f(raw) vs %f(restored)\n", radToDeg(imperial_palace.lon),
         radToDeg(imperial_palace_restored.lon));

  return 0;
}

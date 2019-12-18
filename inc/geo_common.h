/**
 * @brief  Class for latitude and longitude pair
 */
#ifndef GEO_COMMON_H
#define GEO_COMMON_H

namespace geoutility {

// equatorial radius of the earth
const double A = 6378137.0;

// inverse flattening
const double INV_F = 298.257223563;
const double F = 1.0 / INV_F;

// eccentricity
const double E2 = 2.0 * F - F * F;

// polar radius of the earth
const double B = (1.0 - F) * A;

// conversion between degree and radian
double radToDeg(const double rad);
double degToRad(const double deg);

/**
 * @brief  Latitude, longitude, height
 * @remark Expect [rad] for lat and lon
 */
struct Blh {
  double lat;
  double lon;
  double height;
};

/**
 * @brief  East, north, up
 * @remark Expect [meter]
 */
struct Enu {
  double e;
  double n;
  double u;
};

/**
 * @brief  Earth centered, earth fixed
 * @remark Expect [meter]
 */
struct Ecef {
  double x;
  double y;
  double z;
};
}
#endif

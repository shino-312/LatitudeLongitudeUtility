/**
 * @brief  Class for latitude and longitude pair
 */
#ifndef GEO_COMMON_H
#define GEO_COMMON_H

namespace geoutility {
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
  Enu operator+(const Enu& other);
  Enu operator-(const Enu& other);
};

/**
 * @brief  Earth centered, earth fixed
 * @remark Expect [meter]
 */
struct Ecef {
  double x;
  double y;
  double z;
  Ecef operator+(const Ecef& other);
  Ecef operator-(const Ecef& other);
};
}  // namespace geoutility
#endif

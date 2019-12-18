/**
 * @brief  Conversion function for latitude/longitude, ecef, enu
 */
#include "geo_conversion_function.h"
#include <cmath>

namespace geoutility {

Ecef convBlhToEcef(const Blh& blh) {
  const double sinLat = sin(blh.lat);
  const double cosLat = cos(blh.lat);

  const double sinLon = sin(blh.lon);
  const double cosLon = cos(blh.lon);

  const double p = A / sqrt(1 - E2 * sinLat * sinLat);

  const double x = (p + blh.height) * cosLat * cosLon;
  const double y = (p + blh.height) * cosLat * sinLon;
  const double z = (p * (1 - E2) + blh.height) * sinLat;

  return Ecef{x, y, z};
}

Blh convEcefToBlh(const Ecef& ecef) {
  const double Ed2 = (A * A - B * B) / (B * B);  // e'^2
  const double d = sqrt(ecef.x * ecef.x + ecef.y * ecef.y);
  const double t = atan2(ecef.z * A, (d * B));
  const double sinT = sin(t);
  const double cosT = cos(t);

  const double lat = atan2(ecef.z + Ed2 * B * sinT * sinT * sinT,
                           d - E2 * A * cosT * cosT * cosT);
  const double lon = atan2(ecef.y, ecef.x);

  const double sinLat = sin(lat);
  const double p = A / sqrt(1 - E2 * sinLat * sinLat);
  const double height = (d / cos(lat)) - p;

  return Blh{lat, lon, height};
}
}

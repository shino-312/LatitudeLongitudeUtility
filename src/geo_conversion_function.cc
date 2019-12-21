/**
 * @brief  Conversion function for latitude/longitude, ecef, enu
 */
#include "geo_conversion_function.h"
#include <cmath>

namespace geoutility {

// equatorial radius of the earth
static const double A = 6378137.0;

// inverse flattening
static const double INV_F = 298.257223563;
static const double F = 1.0 / INV_F;

// eccentricity
static const double E2 = 2.0 * F - F * F;

// polar radius of the earth
static const double B = (1.0 - F) * A;

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

Enu calcEnu(const Blh& origin, const Blh& destination) {
  const Ecef diff = convBlhToEcef(destination) - convBlhToEcef(origin);

  const double sinLat = sin(origin.lat);
  const double sinLon = sin(origin.lon);
  const double cosLat = cos(origin.lat);
  const double cosLon = cos(origin.lon);

  const double e = -sinLon * diff.x + cosLon * diff.y;
  const double n =
      -cosLon * sinLat * diff.x - sinLon * sinLat * diff.y + cosLat * diff.z;
  const double u =
      cosLon * cosLat * diff.x + sinLon * cosLat * diff.y + sinLat * diff.z;

  return Enu{e, n, u};
}

Blh calcBlh(const Blh& origin, const Enu& diff) {
  const double sinLat = sin(origin.lat);
  const double sinLon = sin(origin.lon);
  const double cosLat = cos(origin.lat);
  const double cosLon = cos(origin.lon);

  const double x =
      -sinLon * diff.e - cosLon * sinLat * diff.n + cosLon * cosLat * diff.u;
  const double y =
      cosLon * diff.e - sinLon * sinLat * diff.n + sinLon * cosLat * diff.u;
  const double z = cosLat * diff.n + sinLat * diff.u;

  return convEcefToBlh(convBlhToEcef(origin) + Ecef{x, y, z});
}
}  // namespace geoutility

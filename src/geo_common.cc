#include "geo_common.h"
#include <cmath>

namespace geoutility {

double radToDeg(const double rad) { return (rad * 180.0 / M_PI); }

double degToRad(const double deg) { return (deg / 180.0 * M_PI); }

Enu Enu::operator+(const Enu& other) {
  Enu ret;
  ret.e = this->e + other.e;
  ret.n = this->n + other.n;
  ret.u = this->u + other.u;
  return ret;
}

Enu Enu::operator-(const Enu& other) {
  Enu ret;
  ret.e = this->e - other.e;
  ret.n = this->n - other.n;
  ret.u = this->u - other.u;
  return ret;
}

Ecef Ecef::operator+(const Ecef& other) {
  Ecef ret;
  ret.x = this->x + other.x;
  ret.y = this->y + other.y;
  ret.z = this->z + other.z;
  return ret;
}

Ecef Ecef::operator-(const Ecef& other) {
  Ecef ret;
  ret.x = this->x - other.x;
  ret.y = this->y - other.y;
  ret.z = this->z - other.z;
  return ret;
}
}  // namespace geoutility

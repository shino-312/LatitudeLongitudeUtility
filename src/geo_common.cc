#include "geo_common.h"
#include <cmath>

namespace geoutility {

double radToDeg(const double rad) { return (rad * 180.0 / M_PI); }

double degToRad(const double deg) { return (deg / 180.0 * M_PI); }
}

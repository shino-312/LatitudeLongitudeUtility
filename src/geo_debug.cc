#include "geo_debug.h"
#include <cstdio>

#define DISABLE_DEBUG_TRACE

namespace geoutility {

void trace(const Blh& blh) {
#ifndef DISABLE_DEBUG_TRACE
  printf("[Blh] lat, lon, height: %f, %f, %f\n", blh.lat, blh.lon, blh.height);
#endif
}

void trace(const Ecef& ecef) {
#ifndef DISABLE_DEBUG_TRACE
  printf("[Ecef] x, y, z: %f, %f, %f\n", ecef.x, ecef.y, ecef.z);
#endif
}

void trace(const Enu& enu) {
#ifndef DISABLE_DEBUG_TRACE
  printf("[Enu] e, n, u: %f, %f, %f\n", enu.e, enu.n, enu.u);
#endif
}
}

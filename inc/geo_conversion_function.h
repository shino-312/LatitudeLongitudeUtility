/**
 * @brief  Conversion function for latitude/longitude, ecef, enu
 */
#ifndef GEO_CONVERSION_FUNCTION_H
#define GEO_CONVERSION_FUNCTION_H

#include "geo_common.h"

namespace geoutility {

Ecef convBlhToEcef(const Blh& blh);
Blh convEcefToBlh(const Ecef& ecef);
}

#endif

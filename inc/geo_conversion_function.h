/**
 * @brief  Conversion function for latitude/longitude, ecef, enu
 */
#ifndef GEO_CONVERSION_FUNCTION_H
#define GEO_CONVERSION_FUNCTION_H

#include "geo_common.h"

namespace geoutility {

/**
 * @brief  Convert from BLH(latitude, longitude, height)
 *         to ECEF coordinate(x, y, z)
 */
Ecef convBlhToEcef(const Blh& blh);

/**
 * @brief  Convert from ECEF coordinate(x, y, z)
 *         to BLH(latitude, longitude, height)
 */
Blh convEcefToBlh(const Ecef& ecef);

/**
 * @brief  Calc ENU based relative distance
 *         from <origin> to <destination>
 */
Enu calcEnu(const Blh& origin, const Blh& destination);

/**
 * @brief  Clac BLH(latitude, longitude, height) of the position
 *         where <diff> away from <origin>
 */
Blh calcBlh(const Blh& origin, const Enu& diff);
}  // namespace geoutility

#endif

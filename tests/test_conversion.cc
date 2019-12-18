#include <gtest/gtest.h>
#include "geo_conversion_function.h"
#include "geo_debug.h"

using namespace geoutility;

static const double DOUBLE_ERR = 0.01;

TEST(BlhEcef, FromBlh) {
  const double lat = degToRad(35.6012679778);
  const double lon = degToRad(139.6847399556);
  const double height = 102.528;

  Blh place = {lat, lon, height};
  trace(place);

  Ecef ret1 = convBlhToEcef(place);
  trace(ret1);

  Blh ret2 = convEcefToBlh(ret1);
  trace(ret2);

  EXPECT_NEAR(place.lat, ret2.lat, DOUBLE_ERR);
  EXPECT_NEAR(place.lon, ret2.lon, DOUBLE_ERR);
  EXPECT_NEAR(place.height, ret2.height, DOUBLE_ERR);
}

TEST(BlhEcef, FromEcef) {
  const double x = -3958850.343750;
  const double y = 3359162.375000;
  const double z = 3692369.093750;

  Ecef place = {x, y, z};
  trace(place);

  Blh ret1 = convEcefToBlh(place);
  trace(ret1);

  Ecef ret2 = convBlhToEcef(ret1);
  trace(ret2);

  EXPECT_NEAR(place.x, ret2.x, DOUBLE_ERR);
  EXPECT_NEAR(place.y, ret2.y, DOUBLE_ERR);
  EXPECT_NEAR(place.z, ret2.z, DOUBLE_ERR);
}

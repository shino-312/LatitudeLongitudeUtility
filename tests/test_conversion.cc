#include <gtest/gtest.h>
#include "geo_conversion_function.h"
#include "geo_debug.h"

using namespace geoutility;

static const double DOUBLE_ERR = 0.001;

TEST(BlhEcef, FromBlh) {
  const double lat = degToRad(35.6012679778);
  const double lon = degToRad(139.6847399556);
  const double height = 102.528;

  Blh place = {lat, lon, height};
  trace(place);

  Ecef tmp = convBlhToEcef(place);
  trace(tmp);

  Blh place_restored = convEcefToBlh(tmp);
  trace(place_restored);

  EXPECT_NEAR(place.lat, place_restored.lat, DOUBLE_ERR);
  EXPECT_NEAR(place.lon, place_restored.lon, DOUBLE_ERR);
  EXPECT_NEAR(place.height, place_restored.height, DOUBLE_ERR);
}

TEST(BlhEcef, FromEcef) {
  const double x = -3958850.343750;
  const double y = 3359162.375000;
  const double z = 3692369.093750;

  Ecef place = {x, y, z};
  trace(place);

  Blh tmp = convEcefToBlh(place);
  trace(tmp);

  Ecef place_restored = convBlhToEcef(tmp);
  trace(place_restored);

  EXPECT_NEAR(place.x, place_restored.x, DOUBLE_ERR);
  EXPECT_NEAR(place.y, place_restored.y, DOUBLE_ERR);
  EXPECT_NEAR(place.z, place_restored.z, DOUBLE_ERR);
}

TEST(BlhEnu, DistanceBetweenTwoLocations) {
  const Blh p1 = {degToRad(35.605459), degToRad(139.680843), 0.0};
  const Blh p2 = {degToRad(35.605508), degToRad(139.681281), 0.0};

  const auto distance = calcEnu(p1, p2);
  trace(distance);

  const auto p2_restored = calcBlh(p1, distance);
  trace(p2_restored);

  EXPECT_NEAR(p2.lat, p2_restored.lat, DOUBLE_ERR);
  EXPECT_NEAR(p2.lon, p2_restored.lon, DOUBLE_ERR);
  EXPECT_NEAR(p2.height, p2_restored.height, DOUBLE_ERR);
}

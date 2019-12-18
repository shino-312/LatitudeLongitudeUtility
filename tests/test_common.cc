#include <gtest/gtest.h>
#include "geo_common.h"

using namespace geoutility;

TEST(MakingInstanceTest, Blh) {
  const double lat = degToRad(35.658581);
  const double lon = degToRad(139.745433);
  const double height = 0.0;

  Blh place = {lat, lon, height};

  EXPECT_DOUBLE_EQ(place.lat, lat);
  EXPECT_DOUBLE_EQ(place.lon, lon);
  EXPECT_DOUBLE_EQ(place.height, height);
}

TEST(MakingInstanceTest, Ecef) {
  const double x = 1.0;
  const double y = 2.0;
  const double z = 3.0;

  Ecef place = {x, y, z};

  EXPECT_DOUBLE_EQ(place.x, x);
  EXPECT_DOUBLE_EQ(place.y, y);
  EXPECT_DOUBLE_EQ(place.z, z);
}

TEST(MakingInstanceTest, Enu) {
  const double e = 1.0;
  const double n = 2.0;
  const double u = 3.0;

  Enu place = {e, n, u};

  EXPECT_DOUBLE_EQ(place.e, e);
  EXPECT_DOUBLE_EQ(place.n, n);
  EXPECT_DOUBLE_EQ(place.u, u);
}

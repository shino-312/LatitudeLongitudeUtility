#include <gtest/gtest.h>
#include "latlon.h"

TEST(LatLonTest, BasicInstanceOperation) {
  const double tokyo_lat = 35.658581;
  const double tokyo_lon = 139.745433;

  // Constructor
  LatLon tokyo = LatLon(tokyo_lat, tokyo_lon);

  EXPECT_DOUBLE_EQ(tokyo.getLat(), tokyo_lat);
  EXPECT_DOUBLE_EQ(tokyo.getLon(), tokyo_lon);

  // Copy constructor
  LatLon tokyo_copy1 = LatLon(tokyo);

  EXPECT_DOUBLE_EQ(tokyo_copy1.getLat(), tokyo_lat);
  EXPECT_DOUBLE_EQ(tokyo_copy1.getLon(), tokyo_lon);

  // Operator=
  LatLon tokyo_copy2;
  EXPECT_LT(tokyo_copy2.getLat(), tokyo_lat);
  EXPECT_LT(tokyo_copy2.getLon(), tokyo_lon);

  tokyo_copy2 = tokyo;

  EXPECT_DOUBLE_EQ(tokyo_copy2.getLat(), tokyo_lat);
  EXPECT_DOUBLE_EQ(tokyo_copy2.getLon(), tokyo_lon);
}

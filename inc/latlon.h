/**
 * @brief  Class for latitude and longitude pair
 */
#ifndef __LAT_LON_H__
#define __LAT_LON_H__

class LatLon {
  public:
    LatLon(): lat_(0.0), lon_(0.0) {}
    LatLon(const double lat, const double lon): lat_(lat), lon_(lon) {}
    virtual ~LatLon() {}
    LatLon(const LatLon&) = default;
    LatLon& operator=(const LatLon&) = default;

    double getLat() const { return lat_; }
    double getLon() const { return lon_; }

  private:
    double lat_;
    double lon_;
};

#endif

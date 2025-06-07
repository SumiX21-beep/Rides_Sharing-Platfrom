#pragma once

class Location {
private:
    double latitude;
    double longitude;

public:
    Location(double lat = 0.0, double lon = 0.0);
    
    double getLatitude() const;
    double getLongitude() const;
    void setLatitude(double lat);
    void setLongitude(double lon);
    
    
    double calculateDistance(const Location& other) const;
    double distanceTo(const Location& other) const; // Alias for calculateDistance
}; 
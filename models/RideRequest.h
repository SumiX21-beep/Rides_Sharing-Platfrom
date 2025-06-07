#pragma once
#include "Location.h"
#include "Vehicle.h"
#include <string>
#include <memory>

class Rider;  

class RideRequest {
private:
    std::string requestId;
    std::shared_ptr<Rider> rider;
    Location pickupLocation;
    Location dropLocation;
    VehicleType preferredVehicleType;
    double estimatedPrice;
    time_t requestTime;

public:
    RideRequest(const std::string& id, std::shared_ptr<Rider> requestRider,
                const Location& pickup, const Location& drop,
                VehicleType vehicleType);

    // Getters
    std::string getRequestId() const;
    std::shared_ptr<Rider> getRider() const;
    Location getPickupLocation() const;
    Location getDropLocation() const;
    VehicleType getPreferredVehicleType() const;
    double getEstimatedPrice() const;
    time_t getRequestTime() const;

    // Setters
    void setEstimatedPrice(double price);
}; 
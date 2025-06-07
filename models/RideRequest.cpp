#include "RideRequest.h"
#include <ctime>

RideRequest::RideRequest(const std::string& id, std::shared_ptr<Rider> requestRider,
                        const Location& pickup, const Location& drop,
                        VehicleType vehicleType)
    : requestId(id),
      rider(requestRider),
      pickupLocation(pickup),
      dropLocation(drop),
      preferredVehicleType(vehicleType),
      estimatedPrice(0.0) {
    requestTime = std::time(nullptr);
}

std::string RideRequest::getRequestId() const {
    return requestId;
}

std::shared_ptr<Rider> RideRequest::getRider() const {
    return rider;
}

Location RideRequest::getPickupLocation() const {
    return pickupLocation;
}

Location RideRequest::getDropLocation() const {
    return dropLocation;
}

VehicleType RideRequest::getPreferredVehicleType() const {
    return preferredVehicleType;
}

double RideRequest::getEstimatedPrice() const {
    return estimatedPrice;
}

time_t RideRequest::getRequestTime() const {
    return requestTime;
}

void RideRequest::setEstimatedPrice(double price) {
    if (price >= 0) {
        estimatedPrice = price;
    }
} 
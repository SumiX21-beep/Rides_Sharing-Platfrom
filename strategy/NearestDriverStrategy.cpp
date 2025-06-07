#include "NearestDriverStrategy.h"
#include <limits>
#include <algorithm>

std::shared_ptr<Driver> NearestDriverStrategy::findMatch(
    const RideRequest& request,
    const std::vector<std::shared_ptr<Driver>>& availableDrivers) {
    
    if (availableDrivers.empty()) {
        return nullptr;
    }

    double minDistance = std::numeric_limits<double>::max();
    std::shared_ptr<Driver> nearestDriver = nullptr;

    
    Location pickupLocation = request.getPickupLocation();
    VehicleType requestedType = request.getPreferredVehicleType();

     
    for (const auto& driver : availableDrivers) {
        if (!driver->getIsAvailable() || 
            driver->getVehicle()->getType() != requestedType) {
            continue;
        }

        double distance = driver->getCurrentLocation().distanceTo(pickupLocation);
        if (distance < minDistance) {
            minDistance = distance;
            nearestDriver = driver;
        }
    }

    return nearestDriver;
} 
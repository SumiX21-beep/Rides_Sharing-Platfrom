#include "RideManager.h"
#include <stdexcept>
#include <algorithm>

RideManager::RideManager(std::shared_ptr<MatchingStrategy> matching,
                        std::shared_ptr<PricingStrategy> pricing)
    : matchingStrategy(matching), pricingStrategy(pricing) {}

std::shared_ptr<Ride> RideManager::createRide(std::shared_ptr<RideRequest> request) {
    // Find matching driver
    auto matchedDriver = matchingStrategy->findMatch(*request, availableDrivers);
    if (!matchedDriver) {
        throw std::runtime_error("No available drivers found");
    }

    // Calculate estimated price
    double estimatedPrice = pricingStrategy->calculatePrice(
        request->getPickupLocation(),
        request->getDropLocation(),
        request->getPreferredVehicleType(),
        request->getRequestTime()
    );
    request->setEstimatedPrice(estimatedPrice);

    // Create new ride
    auto ride = std::make_shared<Ride>(
        "RIDE_" + request->getRequestId(),  // Simple ride ID generation
        request
    );

    // Assign driver
    ride->assignDriver(matchedDriver);
    
    // Add to active rides
    activeRides[ride->getRideId()] = ride;
    
    return ride;
}

void RideManager::startRide(const std::string& rideId) {
    auto ride = getRide(rideId);
    if (!ride) {
        throw std::runtime_error("Ride not found");
    }
    ride->startRide();
}

void RideManager::completeRide(const std::string& rideId) {
    auto ride = getRide(rideId);
    if (!ride) {
        throw std::runtime_error("Ride not found");
    }

    // Calculate final price
    double finalPrice = pricingStrategy->calculatePrice(
        ride->getRequest()->getPickupLocation(),
        ride->getRequest()->getDropLocation(),
        ride->getRequest()->getPreferredVehicleType(),
        ride->getStartTime()
    );

    ride->completeRide(finalPrice);
    
    // Move ride from active to completed
    completedRides[rideId] = ride;
    activeRides.erase(rideId);
}

void RideManager::cancelRide(const std::string& rideId) {
    auto ride = getRide(rideId);
    if (!ride) {
        throw std::runtime_error("Ride not found");
    }
    ride->cancelRide();
    activeRides.erase(rideId);
}

void RideManager::addDriver(std::shared_ptr<Driver> driver) {
    if (driver && driver->getIsAvailable()) {
        availableDrivers.push_back(driver);
    }
}

void RideManager::removeDriver(const std::string& driverId) {
    auto it = std::remove_if(availableDrivers.begin(), availableDrivers.end(),
        [&driverId](const auto& driver) {
            return driver->getUserId() == driverId;
        });
    availableDrivers.erase(it, availableDrivers.end());
}

void RideManager::rateRider(const std::string& rideId, double rating) {
    auto ride = getRide(rideId);
    if (!ride) {
        // Check completed rides if not found in active rides
        auto it = completedRides.find(rideId);
        if (it != completedRides.end()) {
            ride = it->second;
        } else {
            throw std::runtime_error("Ride not found");
        }
    }
    ride->rateRider(rating);
}

void RideManager::rateDriver(const std::string& rideId, double rating) {
    auto ride = getRide(rideId);
    if (!ride) {
        // Check completed rides if not found in active rides
        auto it = completedRides.find(rideId);
        if (it != completedRides.end()) {
            ride = it->second;
        } else {
            throw std::runtime_error("Ride not found");
        }
    }
    ride->rateDriver(rating);
}

std::shared_ptr<Ride> RideManager::getRide(const std::string& rideId) const {
    // First check active rides
    auto it = activeRides.find(rideId);
    if (it != activeRides.end()) {
        return it->second;
    }
    
    // Then check completed rides
    auto completedIt = completedRides.find(rideId);
    if (completedIt != completedRides.end()) {
        return completedIt->second;
    }
    
    return nullptr;
}

const std::vector<std::shared_ptr<Driver>>& RideManager::getAvailableDrivers() const {
    return availableDrivers;
} 
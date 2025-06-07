#pragma once
#include "../models/Ride.h"
#include "../models/RideRequest.h"
#include "../strategy/MatchingStrategy.h"
#include "../pricing/PricingStrategy.h"
#include <memory>
#include <unordered_map>
#include <vector>

class RideManager {
private:
    std::unordered_map<std::string, std::shared_ptr<Ride>> activeRides;
    std::unordered_map<std::string, std::shared_ptr<Ride>> completedRides;
    std::vector<std::shared_ptr<Driver>> availableDrivers;
    std::shared_ptr<MatchingStrategy> matchingStrategy;
    std::shared_ptr<PricingStrategy> pricingStrategy;

public:
    RideManager(std::shared_ptr<MatchingStrategy> matching,
                std::shared_ptr<PricingStrategy> pricing);

    // Core ride management methods
    std::shared_ptr<Ride> createRide(std::shared_ptr<RideRequest> request);
    void startRide(const std::string& rideId);
    void completeRide(const std::string& rideId);
    void cancelRide(const std::string& rideId);
    
    // Driver management
    void addDriver(std::shared_ptr<Driver> driver);
    void removeDriver(const std::string& driverId);
    
    // Rating methods
    void rateRider(const std::string& rideId, double rating);
    void rateDriver(const std::string& rideId, double rating);
    
    // Getters
    std::shared_ptr<Ride> getRide(const std::string& rideId) const;
    const std::vector<std::shared_ptr<Driver>>& getAvailableDrivers() const;
}; 
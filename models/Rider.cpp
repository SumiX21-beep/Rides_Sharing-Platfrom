#include "Rider.h"

Rider::Rider(const std::string& id, const std::string& name,
             const std::string& phone, const std::string& email)
    : User(id, name, phone, email), totalSpent(0.0) {}

const std::vector<std::shared_ptr<Ride>>& Rider::getRideHistory() const {
    return rideHistory;
}

double Rider::getTotalSpent() const {
    return totalSpent;
}

void Rider::addRideToHistory(std::shared_ptr<Ride> ride) {
    rideHistory.push_back(ride);
}

void Rider::updateSpent(double amount) {
    if (amount > 0) {
        totalSpent += amount;
    }
}

void Rider::updateRating(double newRating) {
   
    const double WEIGHT_EXISTING = 0.8;
    const double WEIGHT_NEW = 0.2;
    
    double weightedRating = (getRating() * WEIGHT_EXISTING) + (newRating * WEIGHT_NEW);
    setRating(weightedRating);
} 
#include "Driver.h"

Driver::Driver(const std::string& id, const std::string& name,
               const std::string& phone, const std::string& email,
               std::shared_ptr<Vehicle> assignedVehicle)
    : User(id, name, phone, email), 
      vehicle(assignedVehicle),
      isAvailable(true),
      totalEarnings(0.0) {}

std::shared_ptr<Vehicle> Driver::getVehicle() const {
    return vehicle;
}

bool Driver::getIsAvailable() const {
    return isAvailable;
}

double Driver::getTotalEarnings() const {
    return totalEarnings;
}

void Driver::setVehicle(std::shared_ptr<Vehicle> newVehicle) {
    vehicle = newVehicle;
}

void Driver::setIsAvailable(bool available) {
    isAvailable = available;
}

void Driver::updateEarnings(double amount) {
    if (amount > 0) {
        totalEarnings += amount;
    }
}

void Driver::updateRating(double newRating) {
    // Weighted rating calculation for drivers
    const double WEIGHT_EXISTING = 0.7;
    const double WEIGHT_NEW = 0.3;
    
    double weightedRating = (getRating() * WEIGHT_EXISTING) + (newRating * WEIGHT_NEW);
    setRating(weightedRating);
} 
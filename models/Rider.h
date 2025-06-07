#pragma once
#include "User.h"
#include <vector>
#include <memory>

class Ride;  

class Rider : public User {
private:
    std::vector<std::shared_ptr<Ride>> rideHistory;
    double totalSpent;

public:
    Rider(const std::string& id, const std::string& name,
          const std::string& phone, const std::string& email);

    // Getters
    const std::vector<std::shared_ptr<Ride>>& getRideHistory() const;
    double getTotalSpent() const;

    // Methods
    void addRideToHistory(std::shared_ptr<Ride> ride);
    void updateSpent(double amount);
    
    // Override rating update
    void updateRating(double newRating) override;
}; 
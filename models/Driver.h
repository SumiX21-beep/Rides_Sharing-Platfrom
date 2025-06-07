#pragma once
#include "User.h"
#include "Vehicle.h"
#include <memory>

class Driver : public User {
private:
    std::shared_ptr<Vehicle> vehicle;
    bool isAvailable;
    double totalEarnings;

public:
    Driver(const std::string& id, const std::string& name,
           const std::string& phone, const std::string& email,
           std::shared_ptr<Vehicle> assignedVehicle);

    // Getters
    std::shared_ptr<Vehicle> getVehicle() const;
    bool getIsAvailable() const;
    double getTotalEarnings() const;

    // Setters
    void setVehicle(std::shared_ptr<Vehicle> newVehicle);
    void setIsAvailable(bool available);
    void updateEarnings(double amount);

    // Override rating update
    void updateRating(double newRating) override;
}; 
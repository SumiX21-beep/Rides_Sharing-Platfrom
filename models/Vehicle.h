#pragma once
#include <string>

enum class VehicleType {
    BIKE,
    CAR,
    AUTO,
    SUV
};

class Vehicle {
private:
    std::string vehicleId;
    std::string registrationNumber;
    VehicleType type;
    std::string model;
    std::string color;

public:
    Vehicle(const std::string& id, const std::string& regNumber,
           VehicleType vehicleType, const std::string& vehicleModel,
           const std::string& vehicleColor);

    // Getters
    std::string getVehicleId() const;
    std::string getRegistrationNumber() const;
    VehicleType getType() const;
    std::string getModel() const;
    std::string getColor() const;

    // Setters
    void setRegistrationNumber(const std::string& regNumber);
    void setType(VehicleType vehicleType);
    void setModel(const std::string& vehicleModel);
    void setColor(const std::string& vehicleColor);
}; 
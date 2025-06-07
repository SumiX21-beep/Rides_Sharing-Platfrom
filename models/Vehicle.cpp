#include "Vehicle.h"

Vehicle::Vehicle(const std::string& id, const std::string& regNumber,
                VehicleType vehicleType, const std::string& vehicleModel,
                const std::string& vehicleColor)
    : vehicleId(id), registrationNumber(regNumber), type(vehicleType),
      model(vehicleModel), color(vehicleColor) {}

std::string Vehicle::getVehicleId() const {
    return vehicleId;
}

std::string Vehicle::getRegistrationNumber() const {
    return registrationNumber;
}

VehicleType Vehicle::getType() const {
    return type;
}

std::string Vehicle::getModel() const {
    return model;
}

std::string Vehicle::getColor() const {
    return color;
}

void Vehicle::setRegistrationNumber(const std::string& regNumber) {
    registrationNumber = regNumber;
}

void Vehicle::setType(VehicleType vehicleType) {
    type = vehicleType;
}

void Vehicle::setModel(const std::string& vehicleModel) {
    model = vehicleModel;
}

void Vehicle::setColor(const std::string& vehicleColor) {
    color = vehicleColor;
} 
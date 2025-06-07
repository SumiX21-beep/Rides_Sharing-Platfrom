#pragma once
#include "../models/Location.h"
#include "../models/Vehicle.h"
#include <ctime>

class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;
    virtual double calculatePrice(
        const Location& pickup,
        const Location& drop,
        VehicleType vehicleType,
        time_t requestTime) = 0;
}; 
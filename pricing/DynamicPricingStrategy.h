#pragma once
#include "PricingStrategy.h"

class DynamicPricingStrategy : public PricingStrategy {
private:
    static constexpr double BASE_RATE_PER_KM = 10.0;
    static constexpr double PEAK_MULTIPLIER = 1.5;
    static constexpr double OFF_PEAK_MULTIPLIER = 0.8;

    bool isPeakHour(time_t requestTime) const;
    double getVehicleTypeMultiplier(VehicleType type) const;

public:
    double calculatePrice(
        const Location& pickup,
        const Location& drop,
        VehicleType vehicleType,
        time_t requestTime) override;
}; 
#include "DynamicPricingStrategy.h"
#include <ctime>

bool DynamicPricingStrategy::isPeakHour(time_t requestTime) const {
    struct tm* timeInfo = localtime(&requestTime);
    int hour = timeInfo->tm_hour;
    
    
    return (hour >= 8 && hour <= 10) || (hour >= 17 && hour <= 19);
}

double DynamicPricingStrategy::getVehicleTypeMultiplier(VehicleType type) const {
    switch (type) {
        case VehicleType::BIKE:
            return 0.8;
        case VehicleType::AUTO:
            return 1.0;
        case VehicleType::CAR:
            return 1.5;
        case VehicleType::SUV:
            return 2.0;
        default:
            return 1.0;
    }
}

double DynamicPricingStrategy::calculatePrice(
    const Location& pickup,
    const Location& drop,
    VehicleType vehicleType,
    time_t requestTime) {
    
   
    double distance = pickup.distanceTo(drop);
    double basePrice = distance * BASE_RATE_PER_KM;
    
  
    double vehicleMultiplier = getVehicleTypeMultiplier(vehicleType);
    basePrice *= vehicleMultiplier;
    
   
    if (isPeakHour(requestTime)) {
        basePrice *= PEAK_MULTIPLIER;
    } else {
        basePrice *= OFF_PEAK_MULTIPLIER;
    }
    
    return basePrice;
} 
 
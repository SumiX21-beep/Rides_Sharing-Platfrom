#include "models/Location.h"
#include "models/Vehicle.h"
#include "models/Driver.h"
#include "models/Rider.h"
#include "models/RideRequest.h"
#include "models/RideStatus.h"
#include "strategy/MatchingStrategy.h"
#include "strategy/MatchingStrategyType.h"
#include "strategy/NearestDriverStrategy.h"
#include "pricing/PricingStrategy.h"
#include "pricing/PricingStrategyType.h"
#include "pricing/DynamicPricingStrategy.h"
#include "notification/NotifierType.h"
#include "manager/RideManager.h"
#include <iostream>
#include <memory>
#include <string>
#include <iomanip>

std::string getVehicleTypeString(VehicleType type) {
    switch(type) {
        case VehicleType::BIKE: return "Bike";
        case VehicleType::CAR: return "Car";
        case VehicleType::AUTO: return "Auto";
        case VehicleType::SUV: return "SUV";
        default: return "Unknown";
    }
}

int main() {
    try {
        
        auto matchingStrategy = std::make_shared<NearestDriverStrategy>();
        auto pricingStrategy = std::make_shared<DynamicPricingStrategy>();
        
        
        RideManager rideManager(matchingStrategy, pricingStrategy);

        
        auto rider = std::make_shared<Rider>(
            std::string("R1"),
            std::string("Ram Kunar"),
            std::string("1234567890"),
            std::string("Ram@example.com")
        );
        
       
        auto vehicle = std::make_shared<Vehicle>(
            std::string("V1"),
            std::string("KA01AB1234"),
            VehicleType::CAR,
            std::string("Toyota Camry"),
            std::string("White")
        );
        
       
        auto driver = std::make_shared<Driver>(
            std::string("D1"),
            std::string("Sham kumar"),
            std::string("9876543210"),
            std::string("Sham@example.com"),
            vehicle
        );
        
        
        Location driverLocation(12.9716, 77.5946);
        Location riderPickupLocation(12.9717, 77.5947);
        Location riderDropLocation(12.9718, 77.5948);
        
        driver->setCurrentLocation(driverLocation);
        driver->setIsAvailable(true);
        
        
        rideManager.addDriver(driver);

       
        auto request = std::make_shared<RideRequest>(
            std::string("REQ1"),
            rider,
            riderPickupLocation,
            riderDropLocation,
            VehicleType::CAR
        );

        
        auto ride = rideManager.createRide(request);
        std::cout << "Initial ride details:\n";
        std::cout << "Ride ID: " << ride->getRideId() << std::endl;
        std::cout << "Status: " << static_cast<int>(ride->getStatus()) << "\n\n";

       
        std::cout << "Driver Details:\n";
        std::cout << "Name: " << driver->getName() << std::endl;
        std::cout << "ID: " << driver->getUserId() << std::endl;
        std::cout << "Phone: " << driver->getPhoneNumber() << std::endl;
        std::cout << "Email: " << driver->getEmail() << std::endl;
        std::cout << "Current Location: (" << 
            driver->getCurrentLocation().getLatitude() << ", " << 
            driver->getCurrentLocation().getLongitude() << ")\n\n";

        
        std::cout << "Vehicle Details:\n";
        std::cout << "Vehicle ID: " << vehicle->getVehicleId() << std::endl;
        std::cout << "Registration Number: " << vehicle->getRegistrationNumber() << std::endl;
        std::cout << "Type: " << getVehicleTypeString(vehicle->getType()) << std::endl;
        std::cout << "Model: " << vehicle->getModel() << std::endl;
        std::cout << "Color: " << vehicle->getColor() << "\n\n";

        
        std::cout << "Rider Details:\n";
        std::cout << "Name: " << rider->getName() << std::endl;
        std::cout << "ID: " << rider->getUserId() << std::endl;
        std::cout << "Phone: " << rider->getPhoneNumber() << std::endl;
        std::cout << "Email: " << rider->getEmail() << "\n\n";

        
        std::cout << "Ride Information:\n";
        std::cout << "Pickup Location: (" << 
            riderPickupLocation.getLatitude() << ", " << 
            riderPickupLocation.getLongitude() << ")" << std::endl;
        std::cout << "Drop Location: (" << 
            riderDropLocation.getLatitude() << ", " << 
            riderDropLocation.getLongitude() << ")" << std::endl;
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "Estimated Price: $" << ride->getRequest()->getEstimatedPrice() << "\n\n";

        
        rideManager.startRide(ride->getRideId());
        std::cout << "Ride completion details:\n";
        std::cout << "\"Completing ride...\"\n";
        rideManager.completeRide(ride->getRideId());
        std::cout << "Updated ride status: " << static_cast<int>(ride->getStatus()) << std::endl;
        std::cout << "Final price: $" << ride->getFinalPrice() << "\n\n";

        
        double totalDistance = riderPickupLocation.calculateDistance(riderDropLocation);
        std::cout << "Trip Details:\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Total Distance: " << totalDistance << " km\n\n";

        
        rideManager.rateDriver(ride->getRideId(), 4.85);
        rideManager.rateRider(ride->getRideId(), 4.8);
        
        std::cout << "Rating information:\n";
        std::cout << "\"Rating driver and rider...\"\n";
        std::cout << "Final Ratings:\n";
        std::cout << "Driver Rating: " << 4.85 << std::endl;
        std::cout << "Rider Rating: " << 4.80 << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
} 
#pragma once
#include "RideRequest.h"
#include "Driver.h"
#include "RideStatus.h"
#include <memory>
#include <ctime>

class Ride {
private:
    std::string rideId;
    std::shared_ptr<RideRequest> request;
    std::shared_ptr<Driver> driver;
    RideStatus status;
    double finalPrice;
    time_t startTime;
    time_t endTime;
    double riderRating;
    double driverRating;

public:
    Ride(const std::string& id, std::shared_ptr<RideRequest> rideRequest);

    // Getters
    std::string getRideId() const;
    std::shared_ptr<RideRequest> getRequest() const;
    std::shared_ptr<Driver> getDriver() const;
    RideStatus getStatus() const;
    double getFinalPrice() const;
    time_t getStartTime() const;
    time_t getEndTime() const;
    double getRiderRating() const;
    double getDriverRating() const;

    // Setters and state changes
    void assignDriver(std::shared_ptr<Driver> assignedDriver);
    void startRide();
    void completeRide(double price);
    void cancelRide();
    void rateRider(double rating);
    void rateDriver(double rating);
}; 
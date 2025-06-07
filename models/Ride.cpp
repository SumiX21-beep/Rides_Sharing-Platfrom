#include "Ride.h"
#include "Rider.h"
#include <stdexcept>

Ride::Ride(const std::string& id, std::shared_ptr<RideRequest> rideRequest)
    : rideId(id),
      request(rideRequest),
      status(RideStatus::CREATED),
      finalPrice(0.0),
      startTime(0),
      endTime(0),
      riderRating(0.0),
      driverRating(0.0) {}

std::string Ride::getRideId() const {
    return rideId;
}

std::shared_ptr<RideRequest> Ride::getRequest() const {
    return request;
}

std::shared_ptr<Driver> Ride::getDriver() const {
    return driver;
}

RideStatus Ride::getStatus() const {
    return status;
}

double Ride::getFinalPrice() const {
    return finalPrice;
}

time_t Ride::getStartTime() const {
    return startTime;
}

time_t Ride::getEndTime() const {
    return endTime;
}

double Ride::getRiderRating() const {
    return riderRating;
}

double Ride::getDriverRating() const {
    return driverRating;
}

void Ride::assignDriver(std::shared_ptr<Driver> assignedDriver) {
    if (status != RideStatus::CREATED) {
        throw std::runtime_error("Cannot assign driver - ride not in CREATED state");
    }
    driver = assignedDriver;
    driver->setIsAvailable(false);
    status = RideStatus::DRIVER_ASSIGNED;
}

void Ride::startRide() {
    if (status != RideStatus::DRIVER_ASSIGNED) {
        throw std::runtime_error("Cannot start ride - driver not assigned");
    }
    status = RideStatus::IN_PROGRESS;
    startTime = std::time(nullptr);
}

void Ride::completeRide(double price) {
    if (status != RideStatus::IN_PROGRESS) {
        throw std::runtime_error("Cannot complete ride - ride not in progress");
    }
    status = RideStatus::COMPLETED;
    endTime = std::time(nullptr);
    finalPrice = price;
    
    // Update rider and driver
    request->getRider()->updateSpent(price);
    driver->updateEarnings(price);
    driver->setIsAvailable(true);
    
    // Add ride to rider's history
    request->getRider()->addRideToHistory(std::make_shared<Ride>(*this));
}

void Ride::cancelRide() {
    if (status == RideStatus::COMPLETED) {
        throw std::runtime_error("Cannot cancel completed ride");
    }
    status = RideStatus::CANCELLED;
    if (driver) {
        driver->setIsAvailable(true);
    }
}

void Ride::rateRider(double rating) {
    if (status != RideStatus::COMPLETED) {
        throw std::runtime_error("Cannot rate rider - ride not completed");
    }
    if (rating < 0 || rating > 5) {
        throw std::invalid_argument("Rating must be between 0 and 5");
    }
    riderRating = rating;
    request->getRider()->updateRating(rating);
}

void Ride::rateDriver(double rating) {
    if (status != RideStatus::COMPLETED) {
        throw std::runtime_error("Cannot rate driver - ride not completed");
    }
    if (rating < 0 || rating > 5) {
        throw std::invalid_argument("Rating must be between 0 and 5");
    }
    driverRating = rating;
    driver->updateRating(rating);
} 
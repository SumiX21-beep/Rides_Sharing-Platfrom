#pragma once
#include "../models/Driver.h"
#include "../models/RideRequest.h"
#include <memory>
#include <vector>

class MatchingStrategy {
public:
    virtual ~MatchingStrategy() = default;
    virtual std::shared_ptr<Driver> findMatch(
        const RideRequest& request,
        const std::vector<std::shared_ptr<Driver>>& availableDrivers) = 0;
}; 
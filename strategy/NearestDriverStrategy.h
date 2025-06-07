#pragma once
#include "MatchingStrategy.h"

class NearestDriverStrategy : public MatchingStrategy {
public:
    std::shared_ptr<Driver> findMatch(
        const RideRequest& request,
        const std::vector<std::shared_ptr<Driver>>& availableDrivers) override;
}; 
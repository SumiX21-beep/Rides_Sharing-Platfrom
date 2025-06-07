#pragma once
#include <string>
#include "Location.h"

class User {
protected:
    std::string userId;
    std::string name;
    std::string phoneNumber;
    std::string email;
    double rating;
    Location currentLocation;

public:
    User(const std::string& id, const std::string& userName, 
         const std::string& phone, const std::string& userEmail);
    
    virtual ~User() = default;

    // Getters
    std::string getUserId() const;
    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    double getRating() const;
    Location getCurrentLocation() const;

    // Setters
    void setName(const std::string& userName);
    void setPhoneNumber(const std::string& phone);
    void setEmail(const std::string& userEmail);
    void setRating(double newRating);
    void setCurrentLocation(const Location& location);

    // Update rating
    virtual void updateRating(double newRating);
}; 
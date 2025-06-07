#include "User.h"

User::User(const std::string& id, const std::string& userName, 
           const std::string& phone, const std::string& userEmail)
    : userId(id), name(userName), phoneNumber(phone), email(userEmail), rating(5.0) {}

std::string User::getUserId() const {
    return userId;
}

std::string User::getName() const {
    return name;
}

std::string User::getPhoneNumber() const {
    return phoneNumber;
}

std::string User::getEmail() const {
    return email;
}

double User::getRating() const {
    return rating;
}

Location User::getCurrentLocation() const {
    return currentLocation;
}

void User::setName(const std::string& userName) {
    name = userName;
}

void User::setPhoneNumber(const std::string& phone) {
    phoneNumber = phone;
}

void User::setEmail(const std::string& userEmail) {
    email = userEmail;
}

void User::setRating(double newRating) {
    if (newRating >= 0.0 && newRating <= 5.0) {
        rating = newRating;
    }
}

void User::setCurrentLocation(const Location& location) {
    currentLocation = location;
}

void User::updateRating(double newRating) {
    // Simple average rating calculation
    rating = (rating + newRating) / 2.0;
    if (rating > 5.0) rating = 5.0;
    if (rating < 0.0) rating = 0.0;
} 
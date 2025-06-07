# Ride-Sharing System

A comprehensive C++ implementation of a ride-sharing service that connects riders with drivers, manages ride requests, and handles payments and ratings.

## Table of Contents
- [System Overview](#system-overview)
- [Functional Requirements](#functional-requirements)
- [Non-Functional Requirements](#non-functional-requirements)
- [Design Patterns Used](#design-patterns-used)
- [SOLID Principles Implementation](#solid-principles-implementation)
- [Core Components](#core-components)
- [Building and Running](#building-and-running)
- [Sample Output](#sample-output)

## System Overview

The ride-sharing system is designed to facilitate the following core operations:
- Rider and driver registration
- Ride booking and driver matching
- Dynamic pricing based on various factors
- Real-time location tracking
- Rating system for both riders and drivers
- Ride status management throughout the journey

## Functional Requirements

1. **User Management**
   - Register riders and drivers with personal details
   - Maintain user profiles with ratings
   - Track driver availability status
   - Store user contact information

2. **Vehicle Management**
   - Support multiple vehicle types (BIKE, CAR, AUTO, SUV)
   - Store vehicle details (registration, model, color)
   - Associate vehicles with drivers

3. **Ride Management**
   - Create ride requests with pickup/drop locations
   - Match riders with nearby drivers
   - Track ride status (CREATED, ACCEPTED, STARTED, COMPLETED)
   - Calculate ride fare dynamically
   - Process ride completion and payments

4. **Location Services**
   - Track real-time location of drivers
   - Calculate distance between locations
   - Find nearest available drivers

5. **Rating System**
   - Allow riders to rate drivers
   - Allow drivers to rate riders
   - Maintain rating history
   - Calculate average ratings

## Non-Functional Requirements

1. **Performance**
   - Fast driver matching algorithm
   - Efficient location-based search
   - Quick fare calculation

2. **Scalability**
   - Support for multiple concurrent rides
   - Easily add new vehicle types
   - Extensible pricing strategies

3. **Maintainability**
   - Modular code structure
   - Clear separation of concerns
   - Well-documented classes and methods

4. **Reliability**
   - Proper error handling
   - Data validation
   - System state consistency

5. **Security**
   - Protected user data
   - Secure payment processing
   - Access control for sensitive operations

## Design Patterns Used

1. **Strategy Pattern**
   - `MatchingStrategy`: For implementing different driver matching algorithms
   - `PricingStrategy`: For implementing various pricing models
   - Allows runtime selection of algorithms

2. **Factory Pattern**
   - Used for creating different types of vehicles
   - Ensures proper initialization of complex objects

3. **Observer Pattern**
   - For ride status updates
   - Notification system implementation

4. **Singleton Pattern**
   - RideManager implementation
   - Ensures single point of control for ride operations

## SOLID Principles Implementation

1. **Single Responsibility Principle (SRP)**
   - Each class has a single, well-defined purpose
   - Example: `Location` class handles only location-related operations

2. **Open/Closed Principle (OCP)**
   - New strategies can be added without modifying existing code
   - Vehicle types can be extended without changing core logic

3. **Liskov Substitution Principle (LSP)**
   - `Driver` and `Rider` properly inherit from `User`
   - All strategy implementations are substitutable

4. **Interface Segregation Principle (ISP)**
   - Separate interfaces for different strategies
   - Clean separation between user types

5. **Dependency Inversion Principle (DIP)**
   - High-level modules depend on abstractions
   - Strategy pattern implementations follow DIP

## Core Components

1. **Models**
   - `User`: Base class for system users
   - `Driver`: Manages driver-specific attributes
   - `Rider`: Handles rider-specific functionality
   - `Vehicle`: Stores vehicle information
   - `Location`: Handles geographical coordinates
   - `Ride`: Manages ride lifecycle
   - `RideRequest`: Encapsulates ride request details

2. **Strategies**
   - `MatchingStrategy`: Interface for driver matching
   - `NearestDriverStrategy`: Implementation of driver matching
   - `PricingStrategy`: Interface for price calculation
   - `DynamicPricingStrategy`: Implementation of dynamic pricing

3. **Managers**
   - `RideManager`: Orchestrates ride operations
   - Handles driver-rider matching
   - Manages ride lifecycle

## Building and Running

```bash
# Compile the project
g++ -std=c++17 -I. main.cpp models/*.cpp strategy/*.cpp pricing/*.cpp manager/*.cpp -o ride_sharing

# Run the executable
./ride_sharing
```

## Sample Output

```
PS S:\Hackthon> g++ -std=c++17 -I. main.cpp models/*.cpp strategy/*.cpp pricing/*.cpp manager/*.cpp -o ride_sharing && ./ride_sharing
Initial ride details:
Ride ID: RIDE_REQ1
Status: 2

Driver Details:
Name: Sham kumar
ID: D1
Phone: 9876543210
Email: Sham@example.com
Current Location: (12.9716, 77.5946)

Vehicle Details:
Vehicle ID: V1
Registration Number: KA01AB1234
Type: Car
Model: Toyota Camry
Color: White

Rider Details:
Name: Ram Kunar
ID: R1
Phone: 1234567890
Email: Ram@example.com

Ride Information:
Pickup Location: (12.9717, 77.5947)
Drop Location: (12.9718, 77.5948)
Estimated Price: $0.186312
Type: Car
Model: Toyota Camry
Color: White

Rider Details:
Name: Ram Kunar
ID: R1
Phone: 1234567890
Email: Ram@example.com

Ride Information:
Pickup Location: (12.9717, 77.5947)
Drop Location: (12.9718, 77.5948)
Estimated Price: $0.186312

Ride completion details:
"Completing ride..."
Updated ride status: 5
Final price: $0.186312

Trip Details:
Total Distance: 0.02 km

Rating information:
"Rating driver and rider..."
Final Ratings:
Driver Rating: 4.85
Rider Rating: 4.80

Rider Rating: 4.80

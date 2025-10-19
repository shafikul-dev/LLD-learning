#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

/*
================================================================================
ABSTRACT CLASS - CAR INTERFACE
================================================================================
This abstract class demonstrates the concept of ABSTRACTION in Object-Oriented Programming.

KEY CONCEPTS:
1. ABSTRACT CLASS: Cannot be instantiated directly (no objects can be created)
2. PURE VIRTUAL FUNCTIONS: Functions with = 0 that MUST be implemented by child classes
3. INTERFACE CONTRACT: Defines WHAT operations are available, not HOW they work
4. POLYMORPHISM: Same interface, different implementations

REAL-WORLD ANALOGY:
Think of this as the "car dashboard" - it shows you WHAT buttons/controls are available
(start engine, accelerate, brake, etc.) but doesn't tell you HOW the engine actually works.
The actual implementation is hidden "under the hood" in the concrete classes.

BENEFITS:
- Consistency: All car types have the same interface
- Flexibility: Can swap different car implementations
- Maintainability: Change implementation without affecting client code
- Testing: Easy to create mock objects for testing
================================================================================
*/
class Car {
public:
    // ===== CORE DRIVING OPERATIONS =====
    virtual void startEngine() = 0;           // Start the car engine
    virtual void stopEngine() = 0;            // Turn off the engine
    virtual void shiftGear(int gear) = 0;     // Change gear (1-6 typically)
    virtual void accelerate() = 0;            // Increase speed
    virtual void brake() = 0;                 // Decrease speed/stop
    virtual void turnLeft() = 0;              // Turn left
    virtual void turnRight() = 0;             // Turn right
    virtual void reverse() = 0;               // Move backwards
    
    // ===== STATUS AND INFORMATION =====
    virtual int getCurrentSpeed() const = 0;  // Get current speed
    virtual int getCurrentGear() const = 0;   // Get current gear
    virtual bool isEngineRunning() const = 0; // Check if engine is on
    virtual string getCarInfo() const = 0;    // Get car details
    
    // ===== MAINTENANCE AND DIAGNOSTICS =====
    virtual void checkEngine() = 0;           // Run engine diagnostics
    virtual void refuel() = 0;                // Add fuel
    virtual double getFuelLevel() const = 0;  // Get fuel percentage
    virtual void honk() = 0;                  // Sound the horn
    
    // ===== VIRTUAL DESTRUCTOR =====
    // CRITICAL: Virtual destructor ensures proper cleanup in inheritance
    // Without this, only the base class destructor would be called
    virtual ~Car() = default;  // C++11 style - cleaner than {}
};

/*
================================================================================
CONCRETE CLASS - SPORTS CAR IMPLEMENTATION
================================================================================
This concrete class provides the ACTUAL IMPLEMENTATION of the Car interface

KEY CONCEPTS:
1. CONCRETE CLASS: Can be instantiated (objects can be created)
2. INHERITANCE: Inherits from Car using "public Car"
3. METHOD OVERRIDING: Implements all pure virtual functions from base class
4. ENCAPSULATION: Private data members with public interface

REAL-WORLD ANALOGY:
This is like the actual car with engine, transmission, wheels, etc. It's the
physical implementation that makes the dashboard buttons actually work.

SPORTS CAR CHARACTERISTICS:
- High performance engine
- Fast acceleration (20 km/h per acceleration)
- Sporty sound effects
- Higher fuel consumption
- 6-speed transmission
================================================================================
*/
class SportsCar : public Car {
private:
    // ===== CAR IDENTIFICATION =====
    string brand;
    string model;
    int year;
    
    // ===== ENGINE AND PERFORMANCE =====
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    double fuelLevel;
    double maxSpeed;
    
    // ===== SPORTS CAR SPECIFIC =====
    bool turboMode;
    bool sportMode;
    vector<string> maintenanceHistory;

public:
    // ===== CONSTRUCTOR =====
    SportsCar(string b, string m, int y = 2023) 
        : brand(b), model(m), year(y), isEngineOn(false), 
          currentSpeed(0), currentGear(0), fuelLevel(100.0), 
          maxSpeed(300.0), turboMode(false), sportMode(false) {
        cout << "🏎️  " << brand << " " << model << " " << year << " created!" << endl;
        maintenanceHistory.push_back("Car manufactured");
    }
    
    // ===== DESTRUCTOR =====
    ~SportsCar() {
        cout << "🏎️  " << brand << " " << model << " destroyed!" << endl;
    }

    // ===== CORE DRIVING OPERATIONS IMPLEMENTATION =====
    void startEngine() override {
        if (isEngineOn) {
            cout << "🔧 " << brand << " " << model << " : Engine is already running!" << endl;
            return;
        }
        isEngineOn = true;
        cout << "🚀 " << brand << " " << model << " : Engine starts with a ROAR! VROOM VROOM!" << endl;
        maintenanceHistory.push_back("Engine started");
    }

    void stopEngine() override {
        if (!isEngineOn) {
            cout << "🔧 " << brand << " " << model << " : Engine is already off!" << endl;
            return;
        }
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << "🔇 " << brand << " " << model << " : Engine turned off. Silence..." << endl;
        maintenanceHistory.push_back("Engine stopped");
    }

    void shiftGear(int gear) override {
        if (!isEngineOn) {
            cout << "❌ " << brand << " " << model << " : Engine is off! Cannot shift gear." << endl;
            return;
        }
        if (gear < 0 || gear > 6) {
            cout << "❌ " << brand << " " << model << " : Invalid gear! Use 0-6." << endl;
            return;
        }
        currentGear = gear;
        string gearSound = (gear == 0) ? "NEUTRAL" : "GEAR " + to_string(gear);
        cout << "⚙️  " << brand << " " << model << " : Shifted to " << gearSound << endl;
    }

    void accelerate() override {
        if (!isEngineOn) {
            cout << "❌ " << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        if (fuelLevel <= 0) {
            cout << "⛽ " << brand << " " << model << " : No fuel! Refuel first!" << endl;
            return;
        }
        
        int speedIncrease = sportMode ? 30 : 20;  // Sport mode = faster acceleration
        currentSpeed += speedIncrease;
        
        if (currentSpeed > maxSpeed) {
            currentSpeed = maxSpeed;
            cout << "🏁 " << brand << " " << model << " : MAX SPEED REACHED! " << currentSpeed << " km/h" << endl;
        } else {
            cout << "🏃 " << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
        }
        
        // Fuel consumption
        fuelLevel -= (sportMode ? 2.0 : 1.0);
        if (fuelLevel < 0) fuelLevel = 0;
    }

    void brake() override {
        currentSpeed -= 25;  // Sports cars have better brakes
        if (currentSpeed < 0) currentSpeed = 0;
        cout << "🛑 " << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

    void turnLeft() override {
        if (currentSpeed > 50) {
            cout << "⚠️  " << brand << " " << model << " : Slow down before turning! Current speed: " << currentSpeed << " km/h" << endl;
        } else {
            cout << "↩️  " << brand << " " << model << " : Turning left at " << currentSpeed << " km/h" << endl;
        }
    }

    void turnRight() override {
        if (currentSpeed > 50) {
            cout << "⚠️  " << brand << " " << model << " : Slow down before turning! Current speed: " << currentSpeed << " km/h" << endl;
        } else {
            cout << "↪️  " << brand << " " << model << " : Turning right at " << currentSpeed << " km/h" << endl;
        }
    }

    void reverse() override {
        if (!isEngineOn) {
            cout << "❌ " << brand << " " << model << " : Engine is off! Cannot reverse." << endl;
            return;
        }
        if (currentGear != 0) {
            cout << "❌ " << brand << " " << model << " : Shift to neutral first!" << endl;
            return;
        }
        currentSpeed = -10;  // Reverse speed
        cout << "🔙 " << brand << " " << model << " : Reversing at " << abs(currentSpeed) << " km/h" << endl;
    }

    // ===== STATUS AND INFORMATION IMPLEMENTATION =====
    int getCurrentSpeed() const override {
        return currentSpeed;
    }

    int getCurrentGear() const override {
        return currentGear;
    }

    bool isEngineRunning() const override {
        return isEngineOn;
    }

    string getCarInfo() const override {
        return brand + " " + model + " " + to_string(year) + " (Sports Car)";
    }

    // ===== MAINTENANCE AND DIAGNOSTICS IMPLEMENTATION =====
    void checkEngine() override {
        cout << "🔍 " << brand << " " << model << " : Running diagnostics..." << endl;
        cout << "   ✅ Engine: " << (isEngineOn ? "Running" : "Off") << endl;
        cout << "   ✅ Speed: " << currentSpeed << " km/h" << endl;
        cout << "   ✅ Gear: " << currentGear << endl;
        cout << "   ✅ Fuel: " << fuelLevel << "%" << endl;
        cout << "   ✅ Turbo Mode: " << (turboMode ? "ON" : "OFF") << endl;
        cout << "   ✅ Sport Mode: " << (sportMode ? "ON" : "OFF") << endl;
        maintenanceHistory.push_back("Engine diagnostics completed");
    }

    void refuel() override {
        if (fuelLevel >= 100) {
            cout << "⛽ " << brand << " " << model << " : Tank is already full!" << endl;
            return;
        }
        fuelLevel = 100.0;
        cout << "⛽ " << brand << " " << model << " : Tank refueled to 100%!" << endl;
        maintenanceHistory.push_back("Tank refueled");
    }

    double getFuelLevel() const override {
        return fuelLevel;
    }

    void honk() override {
        cout << "📯 " << brand << " " << model << " : BEEP BEEP! 🚗💨" << endl;
    }

    // ===== SPORTS CAR SPECIFIC METHODS =====
    void toggleTurboMode() {
        turboMode = !turboMode;
        cout << "🚀 " << brand << " " << model << " : Turbo mode " << (turboMode ? "ACTIVATED" : "DEACTIVATED") << endl;
    }

    void toggleSportMode() {
        sportMode = !sportMode;
        cout << "🏁 " << brand << " " << model << " : Sport mode " << (sportMode ? "ACTIVATED" : "DEACTIVATED") << endl;
    }

    void showMaintenanceHistory() {
        cout << "📋 " << brand << " " << model << " Maintenance History:" << endl;
        for (const auto& entry : maintenanceHistory) {
            cout << "   • " << entry << endl;
        }
    }
};

/*
================================================================================
SEDAN CAR IMPLEMENTATION - DIFFERENT BEHAVIOR, SAME INTERFACE
================================================================================
This demonstrates how different concrete classes can implement the same interface
with completely different behaviors - the power of polymorphism!
================================================================================
*/
class SedanCar : public Car {
private:
    string brand;
    string model;
    int year;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    double fuelLevel;
    bool ecoMode;

public:
    SedanCar(string b, string m, int y = 2023) 
        : brand(b), model(m), year(y), isEngineOn(false), 
          currentSpeed(0), currentGear(0), fuelLevel(100.0), ecoMode(true) {
        cout << "🚗 " << brand << " " << model << " " << year << " created!" << endl;
    }

    ~SedanCar() {
        cout << "🚗 " << brand << " " << model << " destroyed!" << endl;
    }

    // Implement all virtual functions with sedan-specific behavior
    void startEngine() override {
        isEngineOn = true;
        cout << "🔧 " << brand << " " << model << " : Engine starts quietly..." << endl;
    }

    void stopEngine() override {
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << "🔇 " << brand << " " << model << " : Engine turned off." << endl;
    }

    void shiftGear(int gear) override {
        if (!isEngineOn) {
            cout << "❌ " << brand << " " << model << " : Engine is off!" << endl;
            return;
        }
        currentGear = gear;
        cout << "⚙️  " << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }

    void accelerate() override {
        if (!isEngineOn) {
            cout << "❌ " << brand << " " << model << " : Engine is off!" << endl;
            return;
        }
        int speedIncrease = ecoMode ? 10 : 15;  // Eco mode = slower acceleration
        currentSpeed += speedIncrease;
        cout << "🚗 " << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
        
        fuelLevel -= (ecoMode ? 0.5 : 1.0);  // Eco mode = less fuel consumption
        if (fuelLevel < 0) fuelLevel = 0;
    }

    void brake() override {
        currentSpeed -= 15;  // Sedans have normal brakes
        if (currentSpeed < 0) currentSpeed = 0;
        cout << "🛑 " << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

    void turnLeft() override {
        cout << "↩️  " << brand << " " << model << " : Turning left at " << currentSpeed << " km/h" << endl;
    }

    void turnRight() override {
        cout << "↪️  " << brand << " " << model << " : Turning right at " << currentSpeed << " km/h" << endl;
    }

    void reverse() override {
        if (!isEngineOn) {
            cout << "❌ " << brand << " " << model << " : Engine is off!" << endl;
            return;
        }
        currentSpeed = -5;  // Slower reverse
        cout << "🔙 " << brand << " " << model << " : Reversing at " << abs(currentSpeed) << " km/h" << endl;
    }

    int getCurrentSpeed() const override { return currentSpeed; }
    int getCurrentGear() const override { return currentGear; }
    bool isEngineRunning() const override { return isEngineOn; }
    string getCarInfo() const override { return brand + " " + model + " " + to_string(year) + " (Sedan)"; }

    void checkEngine() override {
        cout << "🔍 " << brand << " " << model << " : Running diagnostics..." << endl;
        cout << "   ✅ Engine: " << (isEngineOn ? "Running" : "Off") << endl;
        cout << "   ✅ Speed: " << currentSpeed << " km/h" << endl;
        cout << "   ✅ Gear: " << currentGear << endl;
        cout << "   ✅ Fuel: " << fuelLevel << "%" << endl;
        cout << "   ✅ Eco Mode: " << (ecoMode ? "ON" : "OFF") << endl;
    }

    void refuel() override {
        fuelLevel = 100.0;
        cout << "⛽ " << brand << " " << model << " : Tank refueled!" << endl;
    }

    double getFuelLevel() const override { return fuelLevel; }

    void honk() override {
        cout << "📯 " << brand << " " << model << " : Beep beep!" << endl;
    }
};

/*
================================================================================
DEMONSTRATION FUNCTION - POLYMORPHISM IN ACTION
================================================================================
This function demonstrates the power of polymorphism - it can work with ANY Car type
without knowing the specific implementation!
================================================================================
*/
void demonstrateDriving(Car* car) {
    cout << "\n🚗 === DRIVING DEMONSTRATION ===" << endl;
    cout << "Car: " << car->getCarInfo() << endl;
    
    car->startEngine();
    car->checkEngine();
    car->shiftGear(1);
    car->accelerate();
    car->accelerate();
    car->turnLeft();
    car->shiftGear(2);
    car->accelerate();
    car->brake();
    car->honk();
    car->stopEngine();
    cout << "🏁 === END OF DEMONSTRATION ===\n" << endl;
}

/*
================================================================================
MAIN FUNCTION - COMPREHENSIVE DEMONSTRATION
================================================================================
This main function demonstrates:
1. Object creation and polymorphism
2. Different car types with same interface
3. Memory management
4. Real-world usage patterns
================================================================================
*/
int main() {
    cout << "🏁 === C++ ABSTRACTION DEMONSTRATION ===" << endl;
    cout << "This program demonstrates Object-Oriented Programming concepts:" << endl;
    cout << "- Abstract classes and pure virtual functions" << endl;
    cout << "- Inheritance and method overriding" << endl;
    cout << "- Polymorphism and virtual functions" << endl;
    cout << "- Encapsulation and data hiding" << endl;
    cout << "- Memory management with destructors" << endl;
    cout << "==========================================\n" << endl;

    // ===== SPORTS CAR DEMONSTRATION =====
    cout << "🏎️  === SPORTS CAR DEMONSTRATION ===" << endl;
    Car* sportsCar = new SportsCar("Ferrari", "F8", 2023);
    
    // Cast to SportsCar to access specific methods
    SportsCar* ferrari = dynamic_cast<SportsCar*>(sportsCar);
    if (ferrari) {
        ferrari->toggleSportMode();
        ferrari->toggleTurboMode();
    }
    
    demonstrateDriving(sportsCar);
    
    // Show maintenance history
    if (ferrari) {
        ferrari->showMaintenanceHistory();
    }
    
    delete sportsCar;

    // ===== SEDAN CAR DEMONSTRATION =====
    cout << "🚗 === SEDAN CAR DEMONSTRATION ===" << endl;
    Car* sedanCar = new SedanCar("Toyota", "Camry", 2023);
    demonstrateDriving(sedanCar);
    delete sedanCar;

    // ===== POLYMORPHISM DEMONSTRATION =====
    cout << "🔄 === POLYMORPHISM DEMONSTRATION ===" << endl;
    cout << "Creating a fleet of different cars..." << endl;
    
    vector<unique_ptr<Car>> fleet;
    fleet.push_back(make_unique<SportsCar>("Lamborghini", "Huracan", 2023));
    fleet.push_back(make_unique<SedanCar>("Honda", "Accord", 2023));
    fleet.push_back(make_unique<SportsCar>("McLaren", "720S", 2023));
    
    cout << "\nFleet size: " << fleet.size() << " cars" << endl;
    
    // Demonstrate each car in the fleet
    for (size_t i = 0; i < fleet.size(); ++i) {
        cout << "\n--- Car " << (i + 1) << " ---" << endl;
        fleet[i]->startEngine();
        cout << "Info: " << fleet[i]->getCarInfo() << endl;
        cout << "Speed: " << fleet[i]->getCurrentSpeed() << " km/h" << endl;
        cout << "Fuel: " << fleet[i]->getFuelLevel() << "%" << endl;
        fleet[i]->stopEngine();
    }

    cout << "\n🏁 === DEMONSTRATION COMPLETE ===" << endl;
    cout << "Key takeaways:" << endl;
    cout << "✅ Abstract classes define contracts" << endl;
    cout << "✅ Concrete classes implement contracts" << endl;
    cout << "✅ Polymorphism allows same interface, different behavior" << endl;
    cout << "✅ Virtual functions enable runtime method resolution" << endl;
    cout << "✅ Destructors ensure proper cleanup" << endl;
    cout << "✅ Encapsulation hides implementation details" << endl;

    return 0;
}

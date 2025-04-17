#include <iostream>
#include <string>

// Abstract base class for a car with common functionalities
class Car {
protected:
    bool is_engine_running_ = false;
    bool are_brake_pads_ok_ = true;
    bool is_abs_enabled_ = true;
    std::string model_;

public:
    explicit Car(const std::string& model_name) : model_(model_name) {}

    virtual ~Car() = default;

    void StartEngine() {
        is_engine_running_ = true;
        std::cout << model_ << " engine started." << std::endl;
    }

    void StopEngine() {
        is_engine_running_ = false;
        std::cout << model_ << " engine stopped." << std::endl;
    }

    void CheckBrakePads(bool status) {
        are_brake_pads_ok_ = status;
        std::cout << model_ << " brake pads are " << (status ? "in good condition." : "due for replacement.") << std::endl;
    }

    void ToggleABS(bool status) {
        is_abs_enabled_ = status;
        std::cout << model_ << " ABS " << (status ? "enabled." : "disabled.") << std::endl;
    }

    virtual void DisplayStatus() const {
        std::cout << "Model: " << model_ << std::endl;
        std::cout << "Engine: " << (is_engine_running_ ? "Running" : "Off") << std::endl;
        std::cout << "Brake Pads: " << (are_brake_pads_ok_ ? "Good" : "Needs Replacement") << std::endl;
        std::cout << "ABS: " << (is_abs_enabled_ ? "Enabled" : "Disabled") << std::endl;
    }

    virtual void PerformGeneralCheckup() const {
        std::cout << "General checkup for " << model_ << ":" << std::endl;
        std::cout << " - Engine: " << (is_engine_running_ ? "Running" : "Off") << std::endl;
        std::cout << " - Brake Pads: " << (are_brake_pads_ok_ ? "Good" : "Needs Replacement") << std::endl;
        std::cout << " - ABS: " << (is_abs_enabled_ ? "Enabled" : "Disabled") << std::endl;
    }
};

// Derived class for Pride model with specific features
class Pride : public Car {
private:
    bool has_manual_windows_ = true;

public:
    Pride() : Car("Pride") {}

    void ToggleManualWindows(bool state) {
        has_manual_windows_ = state;
        std::cout << "Pride: Manual windows " << (state ? "enabled." : "disabled.") << std::endl;
    }

    void DisplayStatus() const override {
        Car::DisplayStatus();
        std::cout << "Manual Windows: " << (has_manual_windows_ ? "Present" : "Absent") << std::endl;
    }
};

// Derived class for Benz model with advanced features
class Benz : public Car {
private:
    bool is_esp_enabled_ = false;
    bool is_ai_system_active_ = false;
    bool is_sunroof_open_ = false;

public:
    Benz() : Car("Benz") {}

    void ToggleESP(bool state) {
        is_esp_enabled_ = state;
        std::cout << "Benz: ESP " << (state ? "enabled." : "disabled.") << std::endl;
    }

    void ToggleAISystem(bool state) {
        is_ai_system_active_ = state;
        std::cout << "Benz: AI system " << (state ? "enabled." : "disabled.") << std::endl;
    }

    void ToggleSunroof(bool state) {
        is_sunroof_open_ = state;
        std::cout << "Benz: Sunroof " << (state ? "opened." : "closed.") << std::endl;
    }

    void DisplayStatus() const override {
        Car::DisplayStatus();
        std::cout << "ESP: " << (is_esp_enabled_ ? "Enabled" : "Disabled") << std::endl;
        std::cout << "AI System: " << (is_ai_system_active_ ? "Active" : "Inactive") << std::endl;
        std::cout << "Sunroof: " << (is_sunroof_open_ ? "Open" : "Closed") << std::endl;
    }
};

// Main function to demonstrate car functionalities
int main() {
    Pride pride;
    Benz benz;

    std::cout << "Testing Pride:" << std::endl;
    pride.StartEngine();
    pride.ToggleManualWindows(true);
    pride.CheckBrakePads(false);
    pride.ToggleABS(true);
    pride.DisplayStatus();
    pride.PerformGeneralCheckup();
    pride.StopEngine();

    std::cout << "\nTesting Benz:" << std::endl;
    benz.StartEngine();
    benz.ToggleESP(true);
    benz.ToggleAISystem(true);
    benz.ToggleSunroof(true);
    benz.CheckBrakePads(true);
    benz.ToggleABS(true);
    benz.DisplayStatus();
    benz.PerformGeneralCheckup();
    benz.StopEngine();

    return 0;
}

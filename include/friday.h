#include <math.h>

class Car {
    private:
        std::string colour;
        std::string make;
        bool isEngineOn;
        bool isCarLocked;
    
    public: 
        void setColour(std::string newColour) {
            colour = newColour;
        }

        std::string getColour(void) {
            return colour;
        }

        void setMake(std::string newMake) {
            make = newMake;
        }

        std::string getMake(void) {
            return make;
        }
        
        void engineOn(void) {
            if (isEngineOn) {
                output("\nSorry, the engine is already on\n");
            }
            else {
                isEngineOn = true;
            }
        }

        void engineOff(void) {
            if (!isEngineOn) {
                output("\nSorry, the engine is already off\n");
            }
            else {
                isEngineOn = false;
            }
        }
        
        void locked(bool desiredState) {
            if (isCarLocked == true) {
                if (isCarLocked == desiredState) {
                    output("\nSorry, the car is already locked\n");
                }
                else {
                    isCarLocked = false;
                }
            }
            else {
                if (isCarLocked == desiredState) {
                    output("\nSorry, the car is already unlocked\n");
                }
                else {
                    isCarLocked = true;
                }
            }
        }

        void status(void) {
            output("\nCar Status: colour: " + colour + ", make: " + make);

            if (isEngineOn) {
                output(", engine: Running");
            }
            else {
                output(", engine: Off");
            }

            if (isCarLocked) {
                output(", Locked");
            }
            else {
                output(", Unlocked");
            }
        }

        Car() {
            setColour("Blue");
            setMake("Honda");
            isEngineOn = false;
            isCarLocked = true;
        }
};

void makeChoice(Car car) {
    car.status();
    std::string choice = promptUserInput("\n1. Turn Engine On\n2. Turn Engine Off\n3. Lock Car\n4. Unlock Car\nPlease select an option (or 0 to finish): ");

    if (validateNumber(choice, true)) {
        switch (stoi(choice)) {
            case 0:
                output("\nfinished");
                break;
            case 1:
                car.engineOn();
                makeChoice(car);
                break;
            case 2:
                car.engineOff();
                makeChoice(car);
                break;
            case 3:
                car.locked(true);
                makeChoice(car);
                break;
            case 4:
                car.locked(false);
                makeChoice(car);
                break;
            default:
                output("\nERROR: something went wrong\n");
                makeChoice(car);
        }
    }
    else {
        makeChoice(car);
    }
}

void carClass(void) {
    Car car;
    makeChoice(car);
}

class AreaOf {
    public:
        float size(float radius) {
            return boost::math::constants::pi<float>() * (radius * radius);
        }

        float size(float length, float width) {
            return length * width;
        }

        float size(float topBase, float bottomBase, float height) {
            return (topBase + bottomBase) * 2 * height;
        }

        AreaOf() {
            //what is being constructed?????????
        }

}

void areaOf(void) {

}
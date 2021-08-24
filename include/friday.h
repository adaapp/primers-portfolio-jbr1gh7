class Car {
    private:
        std::string colour;
        std::string make;
        bool isEngineOn;
        bool isCarLocked;
    
    public: 
        void set_colour(std::string newColour) {
            colour = newColour;
        }

        std::string get_colour(void) {
            return colour;
        }

        void set_make(std::string newMake) {
            colour = newMake;
        }

        std::string get_make(void) {
            return make;
        }
        
        void engine_on(void) {
            isEngineOn = true;
        }

        void engine_off(void) {
            isEngineOn = false;
        }
        
        void locked(bool) {
            if (isCarLocked) {
                isCarLocked = false;
            }
            else {
                isCarLocked = true;
            }
        }

        void status(void) {
            output("\nCar Status: colour:" + colour + ", make:" + make);

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

        void changeEngineState(Car car, bool desiredState) {
            if (car.isEngineOn == desiredState) {
                if (car.isEngineOn) {
                    output("Sorry, the engine is already on");
                }
                else {
                    output("Sorry, the engine is already off");
                }
            }
            else {
                car.isEngineOn = desiredState;
            }
        }

        void changeLockState(Car car, bool desiredState) {
            if (car.isCarLocked == desiredState) {
                if (car.isCarLocked) {
                    output("Sorry, the car is already locked");
                }
                else {
                    output("Sorry, the car is already unlocked");
                }
            }
            else {
                car.isCarLocked = desiredState;
            }
        }
};

void makeChoice(Car car) {
    car.status();
    std::string choice = promptUserInput("\n1. Turn Engine On\n2. Turn Engine Off\n3. Lock Car\n4. Unlock Car\nPlease select an option (or 0 to finish): ");

    if (validateNumber(choice, true)) {
        switch (stoi(choice)) {
            case 0:
                output("finished");
                break;
            case 1:
                car.changeEngineState(car, true);
                makeChoice(car);
                break;
            case 2:
                car.changeEngineState(car, false);
                makeChoice(car);
                break;
            case 3:
                car.changeLockState(car, true);
                makeChoice(car);
                break;
            case 4:
                car.changeLockState(car, false);
                makeChoice(car);
                break;
            default:
                output("\nERROR: something went wrong");
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


void areaOf(void) {
		std::cout << " - areaOf: not yet implemented\n\n";
}
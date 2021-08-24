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
};

void carClass(void) {
    Car car;

    car.status();
    int choice = promptUserInput("\n1. Turn Engine On\n2. Turn Engine Off\n3. Lock Car\n4. Unlock Car\nPlease select an option (or 0 to finish): ");

    

    
}


void areaOf(void) {
		std::cout << " - areaOf: not yet implemented\n\n";
}
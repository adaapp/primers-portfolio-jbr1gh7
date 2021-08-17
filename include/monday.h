void output(std::string message) {
    std::cout << message;
}

std::string promptUserInput(std::string message) {
    std::string temp;

    output(message);
    std::getline(std::cin, temp);
    return temp;
}

float cToF(float centigrade) {
    return (centigrade * 9 / 5) + 32; //Centigrade to Fahrenheit.
}

float fToC(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9; //Fahrenheit to Centigrade.
}

void fahrenheitCentigradeConversion(void) {
    bool retryChoice = true;
    std::string temperatureString;
    float temperatureFloat;

    while (retryChoice) {
        temperatureString = promptUserInput("\nPlease enter the starting temperature: ");

        try {
            stof(temperatureString);
            temperatureFloat = stof(temperatureString);
            retryChoice = false;

        }
        catch (const std::invalid_argument) {
            output("ERROR: \"" + temperatureString + "\" is not digits. Try again.");
        }
    }

    retryChoice = true;

    while (retryChoice) {
        std::string chosenConversion = promptUserInput("\nPress ‘C’ to convert from Fahrenheit to Centigrade.\nPress ‘F’ to convert from Centigrade to Fahrenheit. \n");

        if (chosenConversion == "C" || chosenConversion == "c") {
            float convertedTemp = fToC(temperatureFloat);
            output("Your choice: C\n");
            output(temperatureString + " degrees Fahrenheit is " + std::to_string(convertedTemp));
            retryChoice = false;
        }
        else if (chosenConversion == "F" || chosenConversion == "f") {
            float convertedTemp = cToF(temperatureFloat);
            output("Your choice: F\n");
            output(temperatureString + " degrees Celsius is " + std::to_string(convertedTemp));
            retryChoice = false;
        }
        else {
            output("ERROR: you inputted an invalid choice. Try again.");
        }
    }
}

void selfServiceCheckout(void) {
    const float taxRate = 5.5;
    int quantity = 1;
    int itemCounter = 0;
    float cumulativeSum = 0.0;
    float currentCost;

	while (quantity > 0) {
        itemCounter ++;
        quantity = stoi(promptUserInput("\nPlease enter a quantity for item " + std::to_string(itemCounter) + " (or 0 to finish): "));
        
        if (quantity > 0) {
            currentCost = stof(promptUserInput("\nPlease enter item " + std::to_string(itemCounter) + "’s cost: "));
            cumulativeSum += quantity * currentCost;
        }
        else {
            //calc tax 
        }
    }
}


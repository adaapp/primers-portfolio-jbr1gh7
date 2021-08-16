void output(std::string message) {
    std::cout << message;
}

std::string promptUserInput(std::string message) {
    std::string temp;

    output(message);
    std::getline(std::cin, temp);
    return temp;
}

std::string floatToString(float floatToCast) {
    return std::to_string(floatToCast);
}

float stringToFloat(std::string stringToCast) {
    return stof(stringToCast);
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
            stringToFloat(temperatureString);
            temperatureFloat = stringToFloat(temperatureString);
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
            output("Your choice: C\n");
            output(temperatureString + " degrees Fahrenheit is " + floatToString(fToC(temperatureFloat)));
            retryChoice = false;
        }
        else if (chosenConversion == "F" || chosenConversion == "f") {
            output("Your choice: F\n");
            output(temperatureString + " degrees Celsius is " + floatToString(cToF(temperatureFloat)));
            retryChoice = false;
        }
        else {
            output("ERROR: you inputted an invalid choice. Try again.");
        }
    }
}

void selfServiceCheckout(void) {
	std::cout << " - selfServiceCheckout: not yet implemented\n\n";
}


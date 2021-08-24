#include <regex>

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

bool validateNumber(std::string toBeValidated, bool isIntExpected = false) {
    bool isValid = true;

    std:: smatch matchLetters;
    std::regex lettersExpression("[^0-9 \\.]"); //if chars other than 0-9 and the escaped literal '.' are present, then search returns true

    if (std::regex_search(toBeValidated, matchLetters, lettersExpression)) {
        isValid = false;
    }

    std::regex decimalsExpression("\\."); //match only '.'

    std::ptrdiff_t occurences(std::distance(
        std::sregex_iterator(toBeValidated.begin(), toBeValidated.end(), decimalsExpression),
        std::sregex_iterator())
    ); //iterate over all matches of '.' and total all occurences with std::distance

    if (!isIntExpected) {
        if (occurences > 1) { //no more than 1 decimal for float
            isValid = false;
        }
    }
    else {
        if (occurences > 0) { //no decimals allowed for int
            isValid = false;
        }
    }

    if (!isValid && !isIntExpected) {
        output("\nERROR: \"" + toBeValidated + "\" is not a valid decimal number. Try again.");
    }
    else if (!isValid && isIntExpected) {
        output("\nERROR: \"" + toBeValidated + "\" is not a valid whole number. Try again.");
    }

    return isValid;
}

void fahrenheitCentigradeConversion(void) {
    bool retryChoice = true;
    float temperatureFloat;
    std::string temperatureString;

    while (retryChoice) {
        temperatureString = promptUserInput("\nPlease enter the starting temperature: ");

        if (validateNumber(temperatureString)) {
            temperatureFloat = stof(temperatureString);
            retryChoice = false;
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
    bool retryChoice = true;
    std::string quantityString;
    std::string currentCostString;

	while (quantity > 0) {
        itemCounter ++;

        while (retryChoice) {
            quantityString = promptUserInput("\nPlease enter a quantity for item " + std::to_string(itemCounter) + " (or 0 to finish): ");
            if (validateNumber(quantityString, true)) {
                quantity = std::stoi(quantityString);
                retryChoice = false;
            }
        }

        retryChoice = true;

        if (quantity > 0) {
            while (retryChoice) {
                currentCostString = promptUserInput("\nPlease enter item " + std::to_string(itemCounter) + "’s cost: ");
                if (validateNumber(currentCostString)) {
                    currentCost = std::stof(currentCostString);
                    cumulativeSum += quantity * currentCost;
                    retryChoice = false;
                }
            }
        }
        else {
            float shoppingTax = cumulativeSum * (taxRate / 100);
            output("\nSubtotal: £" + std::to_string(cumulativeSum) + "\nShopping tax: £" + std::to_string(shoppingTax) + "\n");
            output("\nTotal: £" + std::to_string(cumulativeSum + shoppingTax)); 
        }

        retryChoice = true;
    }
}


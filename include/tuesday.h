int checkPassword(std::string password) {
    std::regex lettersExpression("[a-z A-Z]");

    std::ptrdiff_t letterCount(std::distance(
        std::sregex_iterator(password.begin(), password.end(), lettersExpression),
        std::sregex_iterator())
    );

    std::regex digitsExpression("[0-9]");

    std::ptrdiff_t digitCount(std::distance(
        std::sregex_iterator(password.begin(), password.end(), digitsExpression),
        std::sregex_iterator())
    );

    std:: smatch matchSpecials;
    std::regex specialsExpression("[^a-z A-Z 0-9]");

    if ((letterCount != 0 && digitCount == 0) || (letterCount == 0 && digitCount != 0)) {
        return 1;
    }

    if (password.length() >= 4 && password.length() < 8) {
        if (letterCount > 0 && digitCount > 0) {
            return 2;
        }
    }
    else if (password.length() >= 8) {
        if (letterCount >= 4 && digitCount >= 2) {
            if (std::regex_search(password, matchSpecials, specialsExpression)) {
                return 4;
            }

            return 3;
        }
    }

    return 0;
}

void passwordComplexityChecker(void) {
    while (true) {
        std::string password = promptUserInput("\nEnter your password: ");
        int strength = checkPassword(password);

        switch(strength) {
            case 1:
                output("\nThe password '" + password+ "' is Weak");
                break;
            case 2:
                output("\nThe password '" + password+ "' is Moderate");
                break;
            case 3:
                output("\nThe password '" + password+ "' is Strong");
                break;
            case 4:
                output("\nThe password '" + password+ "' is Very Strong");
                break;
            default:
                output("\nERROR: something went wrong");
        }
    }
}


void employeeListRemoval(void) {
	std::cout << " - employeeListRemoval: not yet implemented\n\n";
}

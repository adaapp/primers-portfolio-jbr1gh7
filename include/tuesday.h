#include <vector>

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
    std::string password = promptUserInput("\nEnter your password: ");
    int strength = checkPassword(password);

    switch(strength) {
        case 1:
            output("\nThe password '" + password + "' is Weak");
            break;
        case 2:
            output("\nThe password '" + password + "' is Moderate");
            break;
        case 3:
            output("\nThe password '" + password + "' is Strong");
            break;
        case 4:
            output("\nThe password '" + password + "' is Very Strong");
            break;
        default:
            output("\nERROR: something went wrong");
            passwordComplexityChecker();
    }
    
}

void outputEmployees(std::vector<std::string> employees) {
    output("\nThere are " + std::to_string(employees.size()) + " employees:");

    for (int i=0; i<employees.size(); i++) {
        output("\n" + employees[i]);
    }
}

void employeeListRemoval(void) {
    std::string toRemove;
	std::vector<std::string> employees = {
        "John Smith",
        "Jaelynn Stuart",
        "Kaley Barajas",
        "Walter Collier",
        "Cale Myers"
    };

    int originalSize = employees.size();

    outputEmployees(employees);

    while (employees.size() == originalSize) {
        toRemove = promptUserInput("\nEnter an employee name to remove: ");
        for (int i=0; i<employees.size(); i++) {
            if (employees[i] == toRemove) {
                employees.erase(employees.begin() + i);
            }
        }

        if (employees.size() == originalSize) {
            output("\nSorry, the name '" + toRemove + "' does not exist in this list.");
        }
    }

    outputEmployees(employees);
}

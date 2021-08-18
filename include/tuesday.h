int checkPassword(password) {
    if (password.length() < 4) {

    }
    else if (password.length() >= 4 && password.length() < 8) {

    }
    else if (password.length() >= 8) {
        
    }
}

void passwordComplexityChecker(void) {
	std::string password = promptUserInput("\nEnter your password");
    checkPassword(password);
}


void employeeListRemoval(void) {
	std::cout << " - employeeListRemoval: not yet implemented\n\n";
}

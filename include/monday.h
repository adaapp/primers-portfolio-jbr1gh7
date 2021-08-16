#include <iostream>
void fahrenheitCentigradeConversion(void) {

    std::string temp;
    float t = 0.0;
    float c = 0.0;
    float f = 0.0;
  

    std::cout << "\nPlease enter the starting temperature: ";
    std::getline(std::cin, temp);
    t = stof(temp);

    std::cout << "\nPress ‘C’ to convert from Fahrenheit to Centigrade";
    std::cout << "\nPress ‘F’ to convert from Centigrade to Fahrenheit.";
    std::getline(std::cin, temp);


    c = (t - 32) * 5 / 9; //Fahrenheit to Centigrade.
    f = (t * 9 / 5) + 32; //Centigrade to Fahrenheit.
    
    std::cout << "\nC = " << c;
    std::cout << "\nF = " << f;
}

void fahrenheitCentigradeConversion();

void selfServiceCheckout(void) {
	std::cout << " - selfServiceCheckout: not yet implemented\n\n";
}


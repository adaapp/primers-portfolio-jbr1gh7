#include <fstream>
#include <vector>
#include <regex>

std::vector<std::string> readFile() {
    std::ifstream file("include/contacts.csv");

    std::string line;
    std::vector<std::string> entries;

    while(getline(file, line)) {
        entries.push_back(line);
    }

    output("Searching " + std::to_string(entries.size()) + " records...\n");
    file.close();
    return entries;
}

void phoneDirectory(void) {
    std::string search = promptUserInput("\nEnter a name or number to search: ");
    std::regex searchExpression(search, std::regex_constants::icase);
    std::sregex_iterator searchIterator;
    std::vector<std::string> data = readFile(); 
    std::string delimiter = ",";
    std::string formatted = ", T: ";
    
    bool isFound = false;

    for (int i=0; i<data.size(); i++) {
        searchIterator = std::sregex_iterator(data[i].begin(), data[i].end(), searchExpression);
        std::ptrdiff_t foundCount(std::distance(
            searchIterator,
            std::sregex_iterator())
        );
        
        if (foundCount > 0) {
            output("\nContact Details:");

            for (std::sregex_iterator j=searchIterator; j!=std::sregex_iterator(); j++) {
                std::string found = data[i];
                size_t start_pos = found.find(delimiter);
                found.replace(start_pos, delimiter.length(), formatted);
                output("\n" + found + "\n");
                isFound = true;
            }
        }
    }
    
    if (!isFound) {
        output("\nSorry, no contact details found"); 
    }
}

void dataFileParser(void) {
	std::cout << " - dataFileParser: not yet implemented\n\n";
}
#include <fstream>
#include <vector>
#include <regex>

std::vector<std::string> readFile(std::string fileName) {
    std::ifstream file(fileName);
    std::string line;
    std::vector<std::string> entries;
  
    while(getline(file, line)) {
        entries.push_back(line);
    }

    file.close();
    return entries;
}

std::vector<std::vector<std::string>> readFile2d(std::string fileName) {
    std::ifstream file(fileName);
    std::string line;
    std::vector<std::vector<std::string>> entries2d;
  
    while(getline(file, line)) {
        std::stringstream stream(line);
        std::string field;
        std::vector<std::string> rowList;

        while(getline(stream, field, ',')) {
            rowList.push_back(field);
        }

        entries2d.push_back(rowList);        
    }

    file.close();
    return entries2d;
}

void phoneDirectory(void) {
    std::string search = promptUserInput("\nEnter a name or number to search: ");
    std::regex searchExpression(search, std::regex_constants::icase);
    std::sregex_iterator searchIterator;
    std::vector<std::string> data = readFile("include/contacts.csv"); 
    std::string delimiter = ",";
    std::string formatted = ", T: ";
    bool isFound = false;

    output("Searching " + std::to_string(data.size()) + " records...\n");

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
	std::vector<std::vector<std::string>> dataGrid = readFile2d("include/salaries.csv");

}
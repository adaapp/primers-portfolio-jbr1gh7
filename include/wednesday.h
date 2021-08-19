#include <fstream>
#include <vector>
#include <regex>

std::vector<std::string> readFile() {
    std::ifstream file("include/contacts.csv");

    std::string line;
    std::vector<std::string> entries;

    while(getline(file, line)) {
        entries.push_back(line);
        output("\n" + line);
    }

    output("\n");
    file.close();
    return entries;
}

void phoneDirectory(void) {
    std::string search = promptUserInput("\nEnter a name or number to search: ");
    std::regex searchExpression(search, std::regex_constants::icase);
    std::sregex_iterator searchIterator;
    std::vector<std::string> data = readFile(); 
    
    bool isFound = false;

    for (int i=0; i<data.size(); i++) {
        searchIterator = std::sregex_iterator(data[i].begin(), data[i].end(), searchExpression);
        std::ptrdiff_t foundCount(std::distance(
            searchIterator,
            std::sregex_iterator())
        );
        
        //output("\n foundCount: " + std::to_string(foundCount));
        if (foundCount > 0) {
            for (std::sregex_iterator j=searchIterator; j!=std::sregex_iterator(); j++) {
                output("\nfound: " + data[i]);
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
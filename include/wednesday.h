#include <fstream>
#include <vector>

std::vector<std::string> readFile() {
    std::ifstream file("include/contacts.csv");

    std::string line;
    std::vector<std::string> entries;

    while(getline(file, line)) {
        entries.push_back(line);
        output("\n" + line);
    }

    file.close();
    return entries;
}

void phoneDirectory(void) {
    std::string search = promptUserInput("\nEnter a name or number to search: ");

    std::vector<std::string> data = readFile(); 

}

void dataFileParser(void) {
	std::cout << " - dataFileParser: not yet implemented\n\n";
}
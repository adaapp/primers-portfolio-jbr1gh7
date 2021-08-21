#include <fstream>
#include <vector>
#include <regex>
#include <locale>

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

std::string findLongestName(std::vector<std::vector<std::string>> dataGrid) {
    int currentLongestLength = 0;
    std::string currentLongestName;

    for(int i=0; i<dataGrid.size(); i++) {
        if (dataGrid[i][1].length() > currentLongestLength) {
            currentLongestLength = dataGrid[i][1].length();
            currentLongestName = dataGrid[i][1];
        } 
    }

    return currentLongestName;
}

std::string createSpacing(std::string stringToSpace, std::string longestName) {
    int spacingLength = longestName.length() - stringToSpace.length();
    std::string spacing = "";
    int padding = 3;

    for (int i=0; i<spacingLength + padding; i++) {
        spacing = spacing + " ";
    }

    return spacing;
}

void dataFileParser(void) {
	std::vector<std::vector<std::string>> dataGrid = readFile2d("include/salaries.csv");
    std::string longestName = findLongestName(dataGrid);

    output(
        std::string("Initial ") + "Last" + createSpacing("Last", longestName) + "Salary" + 
        "\n------ ------" + createSpacing("------", longestName) + "------"
    );

    for(int i=0; i<dataGrid.size(); i++) { //std::transform(str.begin(), str.end(),str.begin(), ::toupper);
        std::string initial = dataGrid[i][0].substr(0,1);
        output(
            "\n" +
            initial + ".    " + 
            dataGrid[i][1] + createSpacing(dataGrid[i][1], longestName) +
            dataGrid[i][2]
        );
    }

}
# Primer Portfolio

## Section 1 - Primer Challenges
### Primer 1 - Fahrenheit / Centigrade Conversion
This challenge requires us to allow a user to enter a value before selecting whether to convert it from Fahrenheit to Centigrade or Centigrade to Fahrenheit.  As part of the initial design the conversion algorithms were needed for both calculations. 

To help complete this challenge I needed to break the overall problem down into the following main tasks: 
* Get data from the user
* Verify the data is in a suitable format
* Create a method to convert F->C
* Create a method to convert C->F
 
#### Reflection (as well as issues, challenges & resolutions)
The biggest issue for me wasn't actually the conversions between the different temperatures, the issue arised in trying to validate the information being input by the user. initially I used a try-catch solution to try casting the string to a float, if there was an error when casting, one could assume that the string doesnt contain valid numbers:
```cpp
try {
    stof(temperatureString);
    temperatureFloat = stof(temperatureString);
    retryChoice = false;
}
catch (const std::invalid_argument) {
    output("ERROR: \"" + temperatureString + "\" is not digits. Try again.");
}
```
However, this method has some slight side effects because a string like '60abcdef' would not produce an exception, because the cast would still work by stripping the 'abcdef' from the string. This was not acceptable and I spent some time figuring out how regex is used in c++. If anything other than numbers or decimals are present, then the number is invalid. If there is more than one decimal for a float, then the string is invalid.
```cpp
std:: smatch matchLetters;
std::regex lettersExpression("[^0-9 \\.]"); //if chars other than 0-9 and the escaped literal '.' are present, then search returns true
```
```cpp
std::regex decimalsExpression("\\."); //match only '.'

std::ptrdiff_t occurences(std::distance(
    std::sregex_iterator(toBeValidated.begin(), toBeValidated.end(), decimalsExpression),
    std::sregex_iterator())
); //iterate over all matches of '.' and total all occurences with std::distance
```
### Primer 2 - Self-service Checkout
This primer required me to create a self-service checkout program in which users enter the quantities and prices of items for the program to calculate a total and include tax ontop of the total.

To help complete this challenge I needed to break the overall problem down into the following main tasks: 
* Get data from the user
* Create a series of while loops so that the program does not continue unless inputs are valid
* Calculate the quantity * cost for each set of items
* Add up the values and calculate tax for a total

This challenge was fairly straightforward as I had done most of the leg work in terms of validating inputs already, one thing that did need adding onto that function was the option to validate if a number was an integer vs a float. This is because the quantities need to be integers, to do this I just used the occurences variable for the number of decimals and checked whether there was more than one decimal (not an integer).
```cpp
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
```
### Primer 3 - Password Complexity Checker
This primer challenged us to to create a program that determines the strength of a password given some defined rules. However, all of the rules are not clear in the brief and they need to be worked out from the desired output by a process of elimination.

To help complete this challenge I needed to break the overall problem down into the following main tasks: 
* Get data from the user
* Work out all conditions that need to be met in order to grade the password
* Measure the occurences of letters, numbers and symbols somehow
* Give a grade decided upon these measurements

When discussing this challenge in class I brought up that regex could be used, but there were some hesitations about using regex as it may not consider all of the rules figured out in the previous stage. Despite this, I maintained confidence that it could be done and I managed to implement regex in my first attempt at solving this challenge through using my experience in the previous primers/personal projects. I simply regex'd capital and lowercase letters and did the same for numbers, counting their occurences using the distance function on a regex iterator containing the pattern. I then did the inverse of this and regex'd for anything other than letters and numbers to find all symbols. I did not use any validation for this one because a password could be any combination of chars.
```cpp
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
```
### Primer 4 - Employee List Removal
This primer challenged us to create a program that displays a list of employee names and prompts the user for an employee name to remove.

To help complete this challenge I needed to break the overall problem down into the following main tasks:
* Get data from the user
* Create a data structure to contain the strings of names
* Search for a name using the input and remove it if match
* Output the names

This challenge was quite easy to complete, the only thing worth noting is that I initially used std::list but I was getting a strange error which I had never encountered before when trying to access the items in the list ``list[item]``:
```
type 'std::list<std::string>' (aka 'list<basic_string<char>>') does not provide a subscript operator
```
I assumed that this would be the same for every other language I have tried but for the standard list in c++ this was not the case. Instead I opted to use a vector instead but it is worth doing some further investigation to figure out why this happened. I thought about using regex for this challenge but I decided not to because the brief looked like the program would only fetch single names so I wasnt sure how I would go about tackling this if there were more than one names that match the pattern.
### Primer 5 - Phone Directory
This challenge required us to write a program that uses an file to store and search for phone contacts by prompting a name or number from the user.

To help complete this challenge I needed to break the overall problem down into the following main tasks:
* Get data from the user
* Read data from file and store in memory during runtime in a data structure
* Compare user input with the data fetched to see if there is a match
* Display match if there is one

The main challenge for me in this primer is that I could have taken the easier route of transposing the file data into a 2d array and then using a ``==`` operator on the vector to compare with the name and the telephone individually ``[[name, telephone],..]``. However I felt that this is not the most robust solution for this challenege. Once again it seemed that regex was the better approach to this. I took the user input and added this string to a regex pattern with a case insensetive flag. The benefit of using regex for this primer is that a user can search for just a section of a number and the program will return all contacts containing that number. Another benefit is that the user will likely search for a name in all lowercase and the program will still return the name regardless of it's capitalisation:
```cpp
std::string search = promptUserInput("\nEnter a name or number to search: ");
std::regex searchExpression(search, std::regex_constants::icase);
std::sregex_iterator searchIterator;
```
### Primer 6 - Data File Parser
The challenege for this primer is to display a list of employee information in a table format, the difficult part is to get the spacing correct.

To help complete this challenge I needed to break the overall problem down into the following main tasks:
* Get data from the user
* Read data from file and store in memory during runtime in a 2d vector
* Find the largest surname
* Figure out spacing using the largest surname and forat accordingly

This challenge was interesting as it reminded me of trying to calculate the spacing of dynamic text in web development. In order to figure out the spacing I needed to first loop through each surname to compare with the latest largest name, constantly replacing this variable with the new largest:
```cpp
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
```
I then took this longest surname and minused it's length with each other word and used this value to create a string of a certain amount of whitespace. I then separated this into its own method so I could reuse it for each word when needed for formatting:

```cpp
std::string createSpacing(std::string stringToSpace, std::string longestName) {
    int spacingLength = longestName.length() - stringToSpace.length();
    std::string spacing = "";
    int padding = 3;

    for (int i=0; i<spacingLength + padding; i++) {
        spacing = spacing + " ";
    }

    return spacing;
}
```
```cpp
output(
    std::string("Initial ") + " Last" + createSpacing("Last", longestName) + "Salary" + 
    "\n------   ------" + createSpacing("------", longestName) + "------"
);
```
### Primer 7 - Sleep Timer
This challenge was pretty easy to complete, I just had to know how to find the current thread of the sleep program using: 
```cpp
void sleepTimer(int seconds = 5) {
	std::this_thread::sleep_for(std::chrono::seconds(seconds));
}
```
### Primer 8 - Joining & Detaching Threads
This primer required me to create a program that initialises two threads that call a unique timer function of different durations. I then needed to join these 2 threads and detach them.

To help complete this challenge I needed to break the overall problem down into the following main tasks:
* Create timers of 5 and 10 second durations on 2 separate threads
* Join these 2 Threads
* Once finished, detach Threads

The challenege for this primer was getting a good idea of what was happening 'under the hood' because the long integers denoting the threads were not very telling of what was going on. Despit this I was able to see that after differing delays that the threads would join in the end and the main thread would end with the 5 second timer ending before the 10 second timer. the detaching was easier to implement as all I had to use was the ``.detach();`` method without having to worry about the timers. 
### Primer 9 - Car Class
This challenge involved creating a car class that has a few different methods that allow the user to unlock and lock the car, turn the engine on and off. It required some private variables and a constructor to instantiate the class.

To help complete this challenge I needed to break the overall problem down into the following main tasks:
* Get input from the user
* Create engine and locking methods
* Create a constructor
* Put everything together in main

This challenge was fairly straightforward, the syntax for creating classes is largely the same as other languages I have used. When writing the methods I was over-complicating it in trying to create a single function that handled both turning the engine off and on, also checking if it was already off/on:

```cpp
void changeEngineState(Car car, bool desiredState) {
    if (car.isEngineOn == desiredState) {
        if (car.isEngineOn) {
            output("Sorry, the engine is already on");
        }
        else {
            output("Sorry, the engine is already off");
        }
    }
    else {
        car.isEngineOn = desiredState;
    }
}

void changeLockState(Car car, bool desiredState) {
    if (car.isCarLocked == desiredState) {
        if (car.isCarLocked) {
            output("Sorry, the car is already locked");
        }
        else {
            output("Sorry, the car is already unlocked");
        }
    }
    else {
        car.isCarLocked = desiredState;
    }
}

```

However I decided against this for 2 reasons: firstly the methods are messy and hard to read because the nested if statements make 2 comparisons to ``car.isEngineOn`` one for checking if the state is the same as what the user wants and then outputtingf the appropriate message. Secondly and more importantly these methods were not part of the class and were meant for the "main()" method of the primer. This means that they didnt actually work because they are trying to access the private variables of the class outside of the class.

### Primer 10 - Area of
This challenge tasked me to create a program that found the area of 3 different 2d shapes using an 'AreaOf' class that only has a method with the same name. I had to use polymorphism (specifically overloading), in order to use the correct formulae for each different shape by taking a different number of arguments per function definition.

To help complete this challenge I needed to break the overall problem down into the following main tasks:
* Work out the conditions needed to overload for each function
* Create 3 ``.size()`` functions for each shapes
* Output the calculations to the user

The main challenge for me in this primer was that the brief stated I needed to have a constructor for my class but I cant see what goes in the constructor. The class only has 3 functions and no private variables that would need to be initialised which would require a constructor. I did include the construcotr but I left it blank as it is not obvious to me what goes in there. I could create the pi as a private constant and intitialise that but I see no point in doing so as this will never change:

```cpp
AreaOf() {
    const float pi = boost::math::constants::pi<float>();
};
```

---
## Section 2 - Programming Paradigms
### Programming Paradigms
Simply put, a programming paradigm, for example, procedural, object-oriented, functional, structured, declarative, imperative and event driven can be described as a specific approach used when trying to solve a problem.  Although many programming languages can (and do) support multiple paradigms this discussion will focus more specifically on the possible benefits with examples of the potential differences and similarities of five from the above list. These are:

### Procedural vs Functional vs Object-oriented
Procedural programming is a paradigm designed upon the principle of programs being a sequential flow of instructions that are ran. It focusses mainly on decomposing problems into groups of sequential instructions called procedures. Similarly to functions, procedural programs use both global and local variables.

Functional programming decomposes programs into functions that use mathematical expressions to evaluate their execution. Functional programming is heavily centered around pure functions with no side-efects and they typically try to avoid the complications that come with sharing both locally and globally scoped data.

Object-oriented programming aims to model the real world through objects. It heavily focusses on the importance of data and who has access to this data. Classes act as "blueprints" for objects, specifying their properties once instantiated. Classes encapsulate methods and data into a single package, abstracting this from the programmer. Classes can also inherit properties from parent classes.

In procedural programming, data is generally dissociated from functions more than OOP because the programs are split up into functions as opposed to objects that encapsulate both data and methods (OOP). There is also no access control for variables such as ``private`` ``public`` ``protected`` etc. this means that procedural programming offers no support for data hiding, making it less secure. However, the top-down approach of procedural programming makes it generally easier to follow as a developer because the focus of the code would not jump around like it would in functional programming, which would jump back and forth over the file as each function would need to be called, perhaps some recursively. The declarations for these functions is also different; in functional programming each function would be defined through some form of mathematical expression using a range of operators whereas procedural programming takes a far simpler approach by just using statements. This helps to add to the 'developer-friendliness' of procedural langauges over more functional paradigms. By splitting up your programs into globally-scoped functions that can be called from different places within the code, it could be argued that functional programming may be seen as more reusable than OOP because the methods in OOP are bound to classes. However with the use of inheritance I believe that this issue is largely avoided by OOP.

### Imperative vs Declarative
Imperative programming is a paradigm that is characterised by instructivity, it focusses on how to solve a problem, specifying each step towards a solution. Therefore it would not use many predefined and abstracted methods to solve problems as these would make it unclear how to solve the problem.

Declarative programming focusses on the opposite, it does not care what needs to be done to solve the problem, all it is concerned with is that it has a desired outcome from a spceific program: it knows what needs to be solved rather than how it needs to be solved.

The issue with imperative programming is that for more complex problems, the code can become very long-winded and consequently confusing because very little is abstracted from the developer to allow them to get to a solution quickly. However imperative programming is quite easy to learn as it follows a step-by-step flow. Declarative programming on the other hand has a very short and succinct way of expressing a solution. However, a high level of abstraction can make things substantially harder to debug because the developer may be less aware of the inner workings of their code.

---
## Section 3 - Continued Professional Development
### Benefits of becoming a Polyglot Programmer
* Employability - If a developer is proficient in multiple languages of multiple different paradigms, then they can increase the breadth of their job search to a much wider net of employers who all use different tech stacks in their solutions. Being a polyglot engineer shows to any employer that you have a good experience as a developer and you can put your mind into many different frames of reference in order to find the best path to a solution.
* Heightened understanding - The ability to effectively traverse multiple different programming paradigms and languages allows you to ascend the confines of only being comfortable with a single langauge. You go from simply knowing syntax of a langauge to knowing the fundamental principles of programming that all languages are built on.
* Fullstack dev - Another benefit of being a poluyglot porgrammer is that you have the ability to contribute to every part of the tech stack; from frontend to APIs to databases, knowing all the languages that specialise in each part of the stack means that you have full control as a developer to provide an end-to-end solution to solve any problem that you can think of. A purely javascript developer for example limits themself to strictly non-dynamic solutions because they have no understanding of database programming or APIS, whereas a fullstack polyglot can create every aspect to a solution.


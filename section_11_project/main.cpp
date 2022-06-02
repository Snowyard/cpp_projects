#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//protostype functions
char menu ();
char selection (function<char ()>, vector<int>&, bool&);
string printNumbers(const vector<int>&);
string addNumber(vector<int>&);
string meanOfNumbers(const vector<int>&);
string smallestNumber(const vector<int>&);
string largestNumber(const vector<int>&);

int main() {
    vector<int> numbers {};
    bool cont {true};
    
    cout << "\nWelcome to Bruno's number program!" << endl;
    
    while(cont) 
        selection(menu, numbers, cont);
    
    cout << "\nThanks for playing!\n" << endl;
    
    
    return 0;
}

char menu () {
    cout << "\n--------------\nP - Print numbers\nA - Add a number\nM - Display mean of numbers\nS - Display the smallest number\n"
            "L - Display the largest number\nQ - Quit\n--------------\n" << endl;
        
    cout << "\nEnter choice: ";
    char userInput {};
    cin >> userInput;
    
    return userInput;
    
}

char selection(function<char ()> menu, vector<int>& numbers, bool& cont) {
    char userInput = menu();
    bool& quit {cont};
    
    switch(toupper(userInput)) {
        
        case 'P':
            cout << "Printing numbers...\n";
            cout << printNumbers(numbers) + "\n";
            break;
            
        case 'A':
            cout << "Adding numbers...\n";
            cout << addNumber(numbers) + "\n";
            break;
            
        case 'M':
            cout << "Finding mean of numbers...\n";
            cout << meanOfNumbers(numbers) + "\n";
            break;
            
        case 'S':
            cout << "Finding smallest number...\n";
            cout << smallestNumber(numbers) << "\n";
            break;
            
        case 'L':
            cout << "Finding largest number...\n";
            cout << largestNumber(numbers) << "\n";
            break;
            
        case 'Q':
            cout << "Quitting program...\n";
            quit = false;
            break;
            
        default:
            cout << "Invalid Input..." << endl;
            break;
    }
    return 0;
}

string printNumbers(const vector<int>& numbers) {
    string text {};
    
    if(numbers.size() == 0) {
        cout << "Add a number first!\n";
    } else {
        for(int i = {0}; i < numbers.size(); i++) {
            text += to_string(numbers.at(i)) + " ";
        }
        cout << endl;
    }
    
    return text;
}

string addNumber(vector<int>& numbers) {
    cout << "Enter a number you wish to add: ";
    int userInput {};
    cin >> userInput;
    
    while(!int(userInput)) {
        cout << "Try again..:";
        cin >> userInput;
    }
    
    numbers.push_back(userInput);
    string text {"You added the number " + to_string(userInput)};
    return text;
}

string meanOfNumbers(const vector<int>& numbers) {
    int total {};
    
    for(int i {0}; i < numbers.size(); i++) {
        total += numbers.at(i);
    }
    if(total == 0) {
        string text {"Add a number first!"};
        return text;
    } else {
        string text {"The mean is: " + to_string(total/numbers.size())};
        return text;
}
}

string smallestNumber(const vector<int>& numbers) {
    if(numbers.size() == 0) {
        cout << "Add a number first!\n";
        string text {""};
        return text;
    } else {
        int min {*min_element(numbers.begin(), numbers.end())};
        string text {"The smallest number is " + to_string(min) + "\n"};
        return text;
    }
}

string largestNumber(const vector<int>& numbers) {
    if(numbers.size() == 0) {
        cout << "Add a number first!\n";
        string text {""};
        return text;
    } else {
        int max {*max_element(numbers.begin(), numbers.end())};
        string text {"The largest number is " + to_string(max) + "\n"};
        return text;
    }
}
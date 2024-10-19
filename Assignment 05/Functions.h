#pragma Once
#include "PriorityQueue.h"

void MainMenu();
int getValidIntInput(const string& prompt);


void MainMenu(){
    cout << "\n--------- Priority Queue ----------\n";
    cout << "\n1.Insert";
    cout << "\n2.Remove";
    cout << "\n3.Exit";
    cout << "\n\nEnter Your Choice: ";
}



int getValidIntInput(const string& prompt) {
    string input;
    int value;
    while (true) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);
        if (ss >> value && ss.eof()) { 
            return value;
        }
        cout << "\nInvalid input, please enter a valid number.\n";
    }
}
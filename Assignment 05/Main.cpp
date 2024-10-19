#include "Functions.h"

int main() {
    
    cout << "\n--------- Priority Queue ----------\n";
    int maxSize = getValidIntInput("\nEnter the Max Size for the Queue: ");
    PriorityQueue<string>* PQ = new PriorityQueue<string>(maxSize);

    vector<string> Admins, Faculty, Students;
    int AdminCounter = 0, FacultyCounter = 0, StudentCounter = 0;
    bool running = true;

    
    while (running) {
        MainMenu();
        int choice = getValidIntInput("");

        switch (choice) {
        case 1: { 
            int numMembers = getValidIntInput("\nHow Many Members do you want to Add: ");

            for (int i = 0; i < numMembers; i++) {
                int roleChoice = 0;
                while (true) {
                    roleChoice = getValidIntInput("\n1. Admin\n2. Faculty\n3. Student\nSelect (1 - 3): ");
                    if (roleChoice >= 1 && roleChoice <= 3) break;
                    cout << "Invalid choice. Please select a number between 1 and 3.\n";
                }

                switch (roleChoice) {
                case 1:
                    Admins.push_back("Admin" + to_string(++AdminCounter));
                    break;
                case 2:
                    Faculty.push_back("Faculty" + to_string(++FacultyCounter));
                    break;
                case 3:
                    Students.push_back("Student" + to_string(++StudentCounter));
                    break;
                }
            }


            int CounterSum = AdminCounter + FacultyCounter + StudentCounter;
            if (CounterSum > PQ->getSize()) {
                cout << "\nQueue Overflow!\n";
            }else {
                for (int i = 0; i < Admins.size(); i++) {
                    PQ->insert(Admins[i]);
                }

                for (int i = 0; i < Faculty.size(); i++) {
                    PQ->insert(Faculty[i]);
                }

                for (int i = 0; i < Students.size(); i++) {
                    PQ->insert(Students[i]);
                }

                cout << "\nItems inserted Successfully!\n";
            }

            break;
        }

        case 2: { 
            if (PQ->isEmpty()) {
                cout << "\nQueue is empty. No items to remove.\n";
            } else {
                
                int numToRemove = getValidIntInput("\nHow many items do you want to remove: ");
                
               
                if (numToRemove > PQ->getSize()) {
                    cout << "\nYou cannot remove more items than are in the queue. Try again.\n";
                } else {
                    for (int i = 0; i < numToRemove; i++) {
                        if (!PQ->isEmpty()) {
                            string item;
                            PQ->remove(item);
                            cout << "\nRemoved item: " << item << endl;
                        }
                    }
                }
            }
            break;
        }

        case 3: {
            running = false;
            cout << "\nExiting the program.\n\n";
            break;
        }

        default:
            cout << "\nInvalid input, please select a valid option.\n";
            break;
        }
    }
    delete PQ;
    return 0;
}

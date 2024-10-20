#include "Functions.h"


int main() {
    
    cout << "\n--------- Priority Queue ----------\n";
    int maxSize = getValidIntInput("\nEnter the Max Size for the Queue: ");
    PriorityQueue<string>* PQ = new PriorityQueue<string>(maxSize);

    string* Admins = new string[maxSize];
    string* Faculty = new string[maxSize];
    string* Students = new string[maxSize];

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
                    if (AdminCounter < maxSize) {
                        Admins[AdminCounter] = "Admin" + to_string(AdminCounter + 1);
                        AdminCounter++;
                    } else {
                        cout << "Admin array is full!\n";
                    }
                    break;
                case 2:
                    if (FacultyCounter < maxSize) {
                        Faculty[FacultyCounter] = "Faculty" + to_string(FacultyCounter + 1);
                        FacultyCounter++;
                    } else {
                        cout << "Faculty array is full!\n";
                    }
                    break;
                case 3:
                    if (StudentCounter < maxSize) {
                        Students[StudentCounter] = "Student" + to_string(StudentCounter + 1);
                        StudentCounter++;
                    } else {
                        cout << "Student array is full!\n";
                    }
                    break;
                }
            }

            int CounterSum = AdminCounter + FacultyCounter + StudentCounter;
            if (CounterSum > PQ->getSize()) {
                cout << "\nQueue Overflow!\n";
            } else {
                for (int i = 0; i < AdminCounter; i++) {
                    PQ->insert(Admins[i]);
                }

                for (int i = 0; i < FacultyCounter; i++) {
                    PQ->insert(Faculty[i]);
                }

                for (int i = 0; i < StudentCounter; i++) {
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

    delete[] Admins;
    delete[] Faculty;
    delete[] Students;
    delete PQ;
    
    return 0;
}

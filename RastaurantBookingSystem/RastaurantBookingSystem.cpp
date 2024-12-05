#include <iostream>
#include <string>
#include <iomanip>
#include "WaitingList.h"
#include "Restaurant.h"
using namespace std;




string centerText(const string& text, int width) {
    int padding = (width - text.length()) / 2;
    return string(padding, ' ') + text + string(width - text.length() - padding, ' ');
}
void displayMenu() {
    const int consoleWidth = 100; 
    const int tableWidth = 80;

    system("cls"); 

    cout << centerText("-------------------- Welcome to the Restaurant --------------------", consoleWidth) << endl;

    cout << centerText("+" + string(tableWidth - 2, '-') + "+", consoleWidth) << endl;
    cout << centerText("| No. |               Option                     |", consoleWidth) << endl;
    cout << centerText("+" + string(tableWidth - 2, '-') + "+", consoleWidth) << endl;

    cout << centerText("|  1  | Book a Table                             |", consoleWidth) << endl;
    cout << centerText("|  2  | Show Booked Tables                       |", consoleWidth) << endl;
    cout << centerText("|  3  | Add Customer to Waiting List             |", consoleWidth) << endl;
    cout << centerText("|  4  | Show Waiting List                        |", consoleWidth) << endl;
    cout << centerText("|  5  | Remove Customer from Waiting List        |", consoleWidth) << endl;
    cout << centerText("|  6  | Exit                                     |", consoleWidth) << endl;
    cout << centerText("+" + string(tableWidth - 2, '-') + "+", consoleWidth) << endl;
}

void executeOption(int option, WaitingList& waitingList, Restaurant& restaurant) {
    string customerName;
    int peopleCount;

    switch (option) {
    case 1:
        cout << "Enter customer's name to book a table: ";
        cin.ignore();
        getline(cin, customerName);
        cout << "Enter the number of people: ";
        cin >> peopleCount;
        restaurant.bookTable(customerName, peopleCount, waitingList);
        break;

    case 2:
        restaurant.showBookedTables();
        break;

    case 3:
        cout << "Enter customer's name to add to the waiting list: ";
        cin.ignore();
        getline(cin, customerName);
        waitingList.Enqueue(customerName);
        break;

    case 4:
        waitingList.ShowWaitingList();
        break;

    case 5:
        waitingList.Dequeue();
        break;

    case 6:
        cout << "Exiting the program...\n";
        break;

    default:
        cout << "Invalid option! Please select a valid option (1-6).\n";
    }
}

int main() {
    int userOption;
    WaitingList waitingList;
    Restaurant restaurant(3);

    do {
        displayMenu();

        cout << "Please select an option (1-6): ";
        cin >> userOption;

        executeOption(userOption, waitingList, restaurant);

        cout << "\nPress any key to return to the menu...";
        cin.ignore();
        cin.get();
    } while (userOption != 6);

    return 0;
}

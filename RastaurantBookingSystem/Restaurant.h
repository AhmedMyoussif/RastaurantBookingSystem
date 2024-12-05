#pragma once
#include <iostream>
#include "WaitingList.h"
using namespace std;

struct TableNode {
    string customerName;
    int peopleCount;
    TableNode* next;

    TableNode(const string& name, int count)
        : customerName(name), peopleCount(count), next(nullptr) {
    }
};

class Restaurant {
private:
    TableNode* head;       
    TableNode* tail;    
    int maxTables;         
    int currentTables;

public:
    Restaurant(int max) : head(nullptr), tail(nullptr), maxTables(max), currentTables(0) {}

    ~Restaurant() {
        while (head != nullptr) {
            TableNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void bookTable(const string& customer, int peopleCount, WaitingList& waitingList) {
        if (currentTables >= maxTables) {
            cout << "No available tables. Adding " << customer << " to the waiting list." << endl;
            waitingList.Enqueue(customer);
        }
        else {
            TableNode* newNode = new TableNode(customer, peopleCount);
            if (head == nullptr) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
            currentTables++;
            cout << "Table booked for " << customer << " with " << peopleCount << " people." << endl;
        }
    }

    void showBookedTables() {
        if (head == nullptr) {
            cout << "No tables booked yet." << endl;
            return;
        }
        cout << "Booked Tables:" << endl;
        TableNode* temp = head;
        while (temp != nullptr) {
            cout << "- " << temp->customerName
                << " (For " << temp->peopleCount << " people)" << endl;
            temp = temp->next;
        }
    }
};

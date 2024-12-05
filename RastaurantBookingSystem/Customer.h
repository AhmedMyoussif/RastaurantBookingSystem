#pragma once
#include <iostream>
#include "Tables.h"
#include "WaitingList.h"
using namespace std;

struct Node {
    string data;
    Node* Next;
    Node(string value) : data(value), Next(nullptr) {}
};

class Customer {
private:
    string name;
    Node* head;
    Tables* tables;
    WaitingList* waitingList;  // ≈÷«›… WaitingList
public:
    Customer(string name, WaitingList* wList, Tables* t) : name(name), head(nullptr), tables(t), waitingList(wList) {}

    void CheckAvailability() {
        if (tables->IsAvailable()) {
            cout << "Tables are available for booking." << endl;
        }
        else {
            cout << "No available tables, please wait." << endl;
        }
    }

    void AddCustomer(string customerName) {
        Node* newNode = new Node(customerName);
        if (head == nullptr) {
            head = newNode;
            newNode->Next = nullptr;
        }
        else {
            Node* temp = head;
            while (temp->Next != nullptr) {
                temp = temp->Next;
            }
            temp->Next = newNode;
        }

        CheckAvailability();

        if (tables->IsAvailable()) {
            tables->BookTable(1);  // ÕÃ“ «·ÿ«Ê·… ··⁄„Ì·
            cout << "Customer " << customerName << " booked a table." << endl;
        }
        else {
            waitingList->Enqueue(customerName);  // ≈÷«›… «·⁄„Ì· ·ﬁ«∆„… «·«‰ Ÿ«—
            cout << "Customer " << customerName << " added to the waiting list." << endl;
        }
    }

    void ShowCustomers() {
        if (head == nullptr) {
            cout << "No customers in the list." << endl;
            return;
        }
        Node* temp = head;
        cout << "Customer List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->Next;
        }
        cout << "NULL" << endl;
    }

    void RemoveCustomer(string customerName) {
        if (head == nullptr) {
            cout << "No customers to remove." << endl;
            return;
        }

        if (head->data == customerName) {
            Node* temp = head;
            head = head->Next;
            delete temp;
            cout << "Customer " << customerName << " removed." << endl;
            return;
        }

        Node* temp = head;
        while (temp->Next != nullptr) {
            if (temp->Next->data == customerName) {
                Node* toDelete = temp->Next;
                temp->Next = temp->Next->Next;
                delete toDelete;
                cout << "Customer " << customerName << " removed." << endl;
                return;
            }
            temp = temp->Next;
        }

        cout << "Customer " << customerName << " not found." << endl;
    }

    // œ«·… · Õ—Ìﬂ «·⁄„Ì· „‰ ﬁ«∆„… «·«‰ Ÿ«— ≈·Ï «·ÿ«Ê·…
    void MoveToTableFromWaitingList() {
        if (!waitingList->IsEmpty()) {
            string customerName = waitingList->Dequeue();
            tables->BookTable(1);  // ÕÃ“ «·ÿ«Ê·… ··⁄„Ì·
            cout << "Customer " << customerName << " moved from waiting list to table." << endl;
        }
    }

    ~Customer() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->Next;
            delete temp;
            temp = nextNode;
        }
    }
};

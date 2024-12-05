#pragma once
#include <iostream>
using namespace std;

struct Node2 { 
    string data;
    Node2* next; 
    Node2(string value) : data(value), next(nullptr) {} 
};

class WaitingList {
private:
    Node2* front;  
    Node2* rear;   

public:
    WaitingList() : front(nullptr), rear(nullptr) {}

    void Enqueue(string name) {
        Node2* newNode = new Node2(name);
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Customer " << name << " added to the waiting list." << endl;
    }

    string Dequeue() {
        if (front == nullptr) {
            cout << "No customers in the waiting list." << endl;
            return "";
        }
        Node2* temp = front;  
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        string name = temp->data;
        delete temp;
        return name;
    }

    void ShowWaitingList() {
        if (front == nullptr) {
            cout << "No customers in the waiting list." << endl;
            return;
        }
        cout << "Waiting List: ";
        Node2* temp = front;  
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << " " << endl;
    }

    bool IsEmpty() {
        return front == nullptr;
    }

    ~WaitingList() {
        while (front != nullptr) {
            Dequeue();
        }
    }
};

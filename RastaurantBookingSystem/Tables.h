#pragma once
#include <iostream>
using namespace std;

class Tables {
private:
    int size, capacity;
    int* arr;
public:
    Tables(int capacity) : capacity(capacity), size(0) {
        arr = new int[capacity];
    }

    void BookTable(int numPeople) {
        if (IsAvailable()) {
            arr[size] = numPeople;
            size++;
            cout << "Table booked for " << numPeople << " people." << endl;
        }
        else {
            cout << "No available tables." << endl;
        }
    }

    bool IsAvailable() {
        return size < capacity;
    }

    void ShowTables() {
        cout << "Booked tables: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " people, ";
        }
        cout << endl;
    }

    ~Tables() {
        delete[] arr;
    }
};

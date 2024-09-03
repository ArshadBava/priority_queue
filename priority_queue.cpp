#include <iostream>
using namespace std;

struct Item {
    int value;
    int priority;
};

Item pr[100];
int size = -1;
const int MAX_SIZE = 100;

bool isFull() {
    return size == MAX_SIZE - 1;
}

bool isEmpty() {
    return size == -1;
}

void enqueue(int value, int priority) {
    if (!isFull()) {
        size++;
        pr[size].value = value;
        pr[size].priority = priority;
        cout << "Inserted element - value: " << value << " Priority: " << priority << "\n";
    } else {
        cout << "Priority queue is full. Cannot enqueue.\n";
    }
}

Item dequeue() {
    Item dequeuedItem = {0, 0};
    if (!isEmpty()) {
        int ind = 0;
        for (int i = 1; i <= size; i++) {
            if (pr[i].priority > pr[ind].priority || 
               (pr[i].priority == pr[ind].priority && pr[i].value > pr[ind].value)) {
                ind = i;
            }
        }
        dequeuedItem = pr[ind];
        // Shift elements left to fill the gap
        for (int i = ind; i < size; i++) {
            pr[i] = pr[i + 1];
        }
        size--;
    } else {
        cout << "Priority queue is empty. Cannot dequeue.\n";
    }
    return dequeuedItem;
}

void display() {
    if (!isEmpty()) {
        cout << "Priority Queue elements: \n";
        for (int i = 0; i <= size; i++) {
            cout << "Value: " << pr[i].value << " Priority: " << pr[i].priority << "\n";
        }
    } else {
        cout << "Priority Queue is empty.\n";
    }
}

int main() {
    cout << "PRIORITY QUEUE\n";
    int value, priority, choice;
    do {
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Element\n";
        cout << "0. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the element value: ";
                cin >> value;
                cout << "Enter the element priority: ";
                cin >> priority;
                enqueue(value, priority);
                break;
            case 2:
                {
                    Item dequeuedItem = dequeue();
                    if (dequeuedItem.value != 0 || dequeuedItem.priority != 0) {
                        cout << "Dequeued element - value: " << dequeuedItem.value << " Priority: " << dequeuedItem.priority << "\n";
                    }
                    break;
                }
            case 3:
                display();
                break;
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);
    return 0;
}


#include <iostream>
using namespace std;

#define MAX 100

class PriorityQueue {
private:
    string names[MAX];
    int priority[MAX];
    int front, rear;

public:
    PriorityQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(string name, int prio) {
        if (isFull()) {
            cout << "Queue is full. Cannot add patient.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }

        names[rear] = name;
        priority[rear] = prio;

        // Sort by priority
        for (int i = front; i < rear; i++) {
            for (int j = i + 1; j <= rear; j++) {
                if (priority[j] < priority[i]) {
                    swap(priority[i], priority[j]);
                    swap(names[i], names[j]);
                }
            }
        }

        cout << "Patient added.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No patient to serve.\n";
            return;
        }

        cout << "Serving patient: " << names[front] << " (Priority " << priority[front] << ")\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void deletePatient(string name) {
        if (isEmpty()) {
            cout << "Queue is empty. No patient to delete.\n";
            return;
        }

        int pos = -1;
        for (int i = front; i <= rear; i++) {
            if (names[i] == name) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "Patient not found.\n";
            return;
        }

        for (int i = pos; i < rear; i++) {
            names[i] = names[i + 1];
            priority[i] = priority[i + 1];
        }

        rear--;
        if (rear < front) {
            front = rear = -1; // Queue is empty now
        }

        cout << "Patient '" << name << "' deleted.\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "\nPatients in queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << i + 1 - front << ". " << names[i] << " - ";
            if (priority[i] == 1)
                cout << "Serious";
            else if (priority[i] == 2)
                cout << "Non-Serious";
            else
                cout << "General Checkup";
            cout << endl;
        }
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    string name;
    int prio;

    do {
        cout << "\n--- Hospital Priority Queue Menu ---\n";
        cout << "1. Add Patient (Enqueue)\n";
        cout << "2. Serve Patient (Dequeue)\n";
        cout << "3. Display Queue\n";
        cout << "4. Delete Patient by Name\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter priority (1-Serious, 2-Non-Serious, 3-General Checkup): ";
                cin >> prio;
                pq.enqueue(name, prio);
                break;

            case 2:
                pq.dequeue();
                break;

            case 3:
                pq.display();
                break;

            case 4:
                cout << "Enter patient name to delete: ";
                cin >> name;
                pq.deletePatient(name);
                break;

            case 5:
                cout << "Exiting.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
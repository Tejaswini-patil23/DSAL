#include <iostream>
using namespace std;

// -------------------- Queue Class --------------------
class Queue {
private:
    int arr[100];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void enqueue(int value) {
        if (rear == 99) {
            cout << "Queue Overflow!" << endl;
        } else {
            if (front == -1) front = 0;
            arr[++rear] = value;
        }
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow!" << endl;
            return -1;
        } else {
            return arr[front++];
        }
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }
};

// -------------------- Input Adjacency Matrix --------------------
void inputAdjMatrix(int adj[10][10], int &n) {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix (" << n << " x " << n << "):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> adj[i][j];
}

// -------------------- Display Adjacency Matrix --------------------
void displayAdjMatrix(int adj[10][10], int n) {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

// -------------------- BFS Function --------------------
void bfs(int adj[10][10], int n, int start) {
    Queue q;
    int visited[10] = {0};

    q.enqueue(start);
    visited[start] = 1;

    cout << "\nBFS Traversal: ";

    while (!q.isEmpty()) {
        int current = q.dequeue();
        cout << current << " ";

        for (int i = 0; i < n; ++i) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                q.enqueue(i);
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

// -------------------- Main --------------------
int main() {
    int adj[10][10], n, start;

    inputAdjMatrix(adj, n);
    displayAdjMatrix(adj, n);

    cout << "\nEnter starting vertex for BFS: ";
    cin >> start;

    bfs(adj, n, start);

    return 0;
}

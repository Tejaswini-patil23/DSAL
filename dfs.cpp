#include <iostream>
using namespace std;

// -------------------- Stack Class --------------------
class Stack {
private:
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == 99) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = value;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return -1;
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    // Super simple peek function (assumes stack is not empty)
    int peek() {
        return arr[top];
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
    cout << "\nAdjacency Matrix\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

// -------------------- Iterative DFS Using Stack --------------------
void dfsIterative(int adj[10][10], int n, int start) {
    Stack s;
    int visited[10] = {0};

    s.push(start);
    visited[start] = 1;

    cout << "\nDFS Traversal: ";

    while (!s.isEmpty()) {
        int current = s.pop();
        cout << current << " ";

        // Push all adjacent unvisited nodes (in reverse order for correct order)
        for (int i = n - 1; i >= 0; --i) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                s.push(i);
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

    cout << "\nEnter starting vertex for DFS: ";
    cin >> start;

    dfsIterative(adj, n, start);

    return 0;
}

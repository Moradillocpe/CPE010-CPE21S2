#include <iostream>
using namespace std;

// Stores adjacency list items
struct adjNode {
    int val, cost;
    adjNode* next;
};

// Structure to store edges
struct graphEdge {
    int start_ver, end_ver, weight;
};

class DiaGraph {
    adjNode* getAdjListNode(int value, int weight, adjNode* head) {
        adjNode* newNode = new adjNode;

        newNode->val = value;
        newNode->cost = weight;
        newNode->next = head;

        return newNode;
    }

    int N;

public:
    adjNode** head;

    DiaGraph(graphEdge edges[], int n, int N) {
        this->N = N;

        head = new adjNode*[N];

        for (int i = 0; i < N; ++i) {
            head[i] = nullptr;
        }

        for (int i = 0; i < n; ++i) {
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            int weight = edges[i].weight;

            adjNode* newNode =
                getAdjListNode(end_ver, weight, head[start_ver]);

            head[start_ver] = newNode;
        }
    }

    ~DiaGraph() {
        for (int i = 0; i < N; ++i) {
            adjNode* current = head[i];

            while (current != nullptr) {
                adjNode* next = current->next;
                delete current;
                current = next;
            }
        }

        delete[] head;
    }
};

// A.1 
void displayVertices(int N) {
    cout << "Vertices: ";

    for (int i = 0; i < N; ++i) {
        cout << char('A' + i);

        if (i < N - 1)
            cout << ", ";
    }

    cout << endl;
}



// A.2 
void displayAdjMatrix(graphEdge edges[], int n, int N) {
    int matrix[10][10] = {};

    for (int i = 0; i < n; ++i) {
        int start = edges[i].start_ver;
        int end = edges[i].end_ver;
        int weight = edges[i].weight;

        matrix[start][end] = weight;
    }

    cout << "\nAdjacency Matrix\n\n";

    cout << "  ";
    for (int i = 0; i < N; ++i) {
        cout << char('A' + i) << " ";
    }
    cout << endl;

    for (int i = 0; i < N; ++i) {
        cout << char('A' + i) << " ";

        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

// A.3
void display_AdjList(adjNode* ptr, int i) {
    while (ptr != nullptr) {
        cout << "(" << char('A' + i) << ", "
             << char('A' + ptr->val) << ", "
             << ptr->cost << ")" << endl;

        ptr = ptr->next;
    }
}

int main() {

    // Graph edges
    graphEdge edges[] = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 4, 3},
        {2, 3, 2},
        {3, 1, 4},
        {4, 3, 3}
    };

    int N = 6;

    int n = sizeof(edges) / sizeof(edges[0]);

    DiaGraph diagraph(edges, n, N);

    // A.1 Create a Graph
    cout << "A.1 Create a Graph" << endl;
    displayVertices(N);

    // A.2 Adjacency Matrix
    cout << "\nA.2 Adjacency Matrix" << endl;
    displayAdjMatrix(edges, n, N);

    // A.3 Adjacency List
    cout << "\nA.3 Adjacency List" << endl;
    cout << "(Start Vertex, End Vertex, Weight)" << endl;

    for (int i = 0; i < N; ++i) {
        display_AdjList(diagraph.head[i], i);
    }

    return 0;
}















#include <bits/stdc++.h>
using namespace std;


#define N 3

vector<vector<int>> goalState;

// Possible moves: Down, Up, Right, Left
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

struct Node {
    vector<vector<int>> state;  // Current puzzle configuration
    int g, h;                   // Cost from start to current node and Heuristic cost (Manhattan distance)
    string path;
    pair<int, int> blankPos;

    Node(vector<vector<int>> s, int g_, string p, pair<int, int> bp)
        : state(s), g(g_), path(p), blankPos(bp) {
        h = calculateHeuristic(s);
    }

    // Total cost function f(n) = g(n) + h(n)
    int f() const {
        return g + h;
    }

    // Comparison operator for priority queue
    bool operator>(const Node& other) const {
        return f() > other.f();
    }

    // Calculate Manhattan distance heuristic
    static int calculateHeuristic(const vector<vector<int>>& state) {
        int dist = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                int val = state[i][j];
                if (val != 0) {
                    for (int x = 0; x < N; x++)
                        for (int y = 0; y < N; y++)
                            if (goalState[x][y] == val)
                                dist += abs(i - x) + abs(j - y);
                }
            }
        return dist;
    }
};

// Convert matrix to string for visited set
string serialize(const vector<vector<int>>& v) {
    string s;
    for (auto& row : v)
        for (auto& num : row)
            s += to_string(num);
    return s;
}

// Check if coordinates are within bounds
bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// Print a puzzle state
void printMatrix(const vector<vector<int>>& mat) {
    for (auto& row : mat) {
        for (int x : row)
            cout << x << " ";
        cout << "\n";
    }
}

// A* search algorithm implementation
void aStar(vector<vector<int>> startState) {
    // Find blank position in the start state
    pair<int, int> blank;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (startState[i][j] == 0)
                blank = { i, j };

    // Priority queue for open list, sorted by f value
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    // Set to track visited states
    set<string> visited;

    // Add start state to open list and visited set
    pq.push(Node(startState, 0, "", blank));
    visited.insert(serialize(startState));

    // Main search loop
    while (!pq.empty()) {
        // Get the node with lowest f value
        Node current = pq.top();
        pq.pop();

        // Display current state being explored
        cout << "\nState with F = " << current.f() << ", G = " << current.g << ", H = " << current.h << ":\n";
        printMatrix(current.state);

        // Check if we've reached the goal
        if (current.h == 0) {
            cout << "\n✅ Goal Reached!\n";
            cout << "Total Steps (G): " << current.g << "\n";
            cout << "Moves (U=Up, D=Down, L=Left, R=Right): " << current.path << "\n";
            return;
        }

        // Explore all possible moves
        for (int d = 0; d < 4; ++d) {
            int newX = current.blankPos.first + dx[d];
            int newY = current.blankPos.second + dy[d];

            // Check if move is valid
            if (isValid(newX, newY)) {
                vector<vector<int>> newState = current.state;
                swap(newState[current.blankPos.first][current.blankPos.second], newState[newX][newY]);

                // Check if this state has been visited
                string serial = serialize(newState);
                if (visited.find(serial) == visited.end()) {
                    // Direction characters: Down, Right, Up, Left
                    string move = "DRUL"; // Direction chars

                    // Add new state to open list and mark as visited
                    pq.push(Node(newState, current.g + 1, current.path + move[d], { newX, newY }));
                    visited.insert(serial);
                }
            }
        }
    }

    cout << "❌ No solution found.\n";
}

// Helper function to input a matrix from user
vector<vector<int>> inputMatrix(const string& name) {
    cout << "Enter " << name << " state (3x3):\n";
    vector<vector<int>> mat(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> mat[i][j];
    return mat;
}

int main() {
    vector<vector<int>> start = inputMatrix("initial");
    goalState = inputMatrix("goal");

    cout << "\n🔎 Solving using A* Search (Manhattan Distance)...\n";
    aStar(start);

    return 0;
}
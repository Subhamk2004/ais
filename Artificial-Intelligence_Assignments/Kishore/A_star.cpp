#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>

const vvi goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

int manhattan(vvi& state) {
    int dist = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (state[i][j] != 0) {
                int value = state[i][j];
                int row_val = (value - 1) / 3;
                int col_val = (value - 1) % 3;
                dist += abs(i - row_val) + abs(j - col_val);
            }
        }
    }
    return dist;
}

vvvi neighbour(vvi& state) {
    vvvi neighbours;
    int pos[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int zero_row = -1, zero_col = -1;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (state[i][j] == 0) {
                zero_row = i;
                zero_col = j;
                break;
            }
        }
    }

    for (auto& p : pos) {
        int new_row = zero_row + p[0];
        int new_col = zero_col + p[1];

        if (new_row >= 0 && new_row < 3 && new_col >= 0 && new_col < 3) {
            vvi new_state = state;
            swap(new_state[zero_row][zero_col], new_state[new_row][new_col]);
            neighbours.push_back(new_state);
        }
    }

    return neighbours;
}

vvvi a_star(vvi& start) {
    set<pair<int, pair<int, pair<vvi, vvvi>>>> st; // (f, g, (state, path))
    set<vvi> check;  // moved outside the loop — fix!

    int g = 0;
    int h = manhattan(start);
    int f = g + h;

    st.insert({f, {g, {start, {start}}}});

    while (!st.empty()) {
        auto [f, rest] = *st.begin();
        int g = rest.first;
        vvi current = rest.second.first;
        vvvi path = rest.second.second;
        st.erase(st.begin());//imp

        if (check.count(current)) continue;
        check.insert(current);

        if (current == goal) return path;

        for (auto& it : neighbour(current)) {
            if (check.count(it)) continue;

            int new_g = g + 1;
            int new_h = manhattan(it);
            int new_f = new_g + new_h;

            vvvi new_path = path;
            new_path.push_back(it);

            st.insert({new_f, {new_g, {it, new_path}}});
        }
    }

    return {};  // no solution
}

void print(vvi& ans) {
    for (auto& row : ans) {
        for (auto it : row) {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vvi start = {
        {1, 2, 3},
        {4, 0, 5},
        {7, 8, 0}
    };

    cout << "Initial Manhattan Distance: " << manhattan(start) << "\n\n";

    vvvi ans = a_star(start);

    if (!ans.empty()) {
        cout << "Solution Path:\n";
        for (auto& state : ans) {
            print(state);
        }
        cout << "Total Moves: " << ans.size() - 1 << endl;
    } else {
        cout << "No Solution Found" << endl;
    }

    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// #define vvi vector<vector<int>>
// #define vi vector<int>
// #define vvvi vector<vector<vector<int>>>
// // Goal state
// const vector<vector<int>> GOAL = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

// // Manhattan distance heuristic
// int manhattan(const vector<vector<int>>& state) {
//     int distance = 0;
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             if (state[i][j] != 0) {
//                 int value = state[i][j];
//                 int target_row = (value - 1) / 3;
//                 int target_col = (value - 1) % 3;
//                 distance += abs(i - target_row) + abs(j - target_col);
//             }
//         }
//     }
//     return distance;
// }

// // Get neighboring states
// vector<vector<vector<int>>> get_neighbors(const vector<vector<int>>& state) {
//     vector<vector<vector<int>>> neighbors;
//     int zero_row, zero_col;
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             if (state[i][j] == 0) {
//                 zero_row = i;
//                 zero_col = j;
//                 break;
//             }
//         }
//     }
//     int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//     for (const auto& move : moves) {
//         int new_row = zero_row + move[0];
//         int new_col = zero_col + move[1];
//         if (new_row >= 0 && new_row < 3 && new_col >= 0 && new_col < 3) {
//             vector<vector<int>> new_state = state;
//             swap(new_state[zero_row][zero_col], new_state[new_row][new_col]);
//             neighbors.push_back(new_state);
//         }
//     }
//     return neighbors;
// }

// // Simplified A* algorithm using set
// vector<vector<vector<int>>> a_star(vector<vector<int>> start) {
//     using State = vector<vector<int>>;
//     // Set: (f_score, g_score, state, path)
//     set<pair<int, pair<int, pair<State, vector<State>>>>> open_list;
//     set<State> closed;
    
//     int g = 0;
//     int h = manhattan(start);
//     open_list.insert({g + h, {g, {start, {start}}}});
    
//     while (!open_list.empty()) {
//         auto [f, rest] = *open_list.begin();
//         g = rest.first;
//         State current = rest.second.first;
//         vector<State> path = rest.second.second;
//         open_list.erase(open_list.begin());
        
//         if (current == GOAL) {
//             return path;
//         }
        
//         if (closed.count(current)) {
//             continue;
//         }
//         closed.insert(current);
        
//         for (const auto& neighbor : get_neighbors(current)) {
//             if (closed.count(neighbor)) {
//                 continue;
//             }
//             int new_g = g + 1;
//             int new_h = manhattan(neighbor);
//             int new_f = new_g + new_h;
//             vector<State> new_path = path;
//             new_path.push_back(neighbor);
//             open_list.insert({new_f, {new_g, {neighbor, new_path}}});
//         }
//     }
    
//     return {};
// }

// // Print state
// void print_state(const vector<vector<int>>& state) {
//     for (const auto& row : state) {
//         for (int val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

// int main() {
//     vector<vector<int>> start = {{1, 2, 3}, {4, 0, 6}, {7, 5, 8}};
//     auto solution = a_star(start);
    
//     if (!solution.empty()) {
//         for (const auto& state : solution) {
//             print_state(state);
//         }
//     } else {
//         cout << "No solution found" << endl;
//     }
    
//     return 0;
// }
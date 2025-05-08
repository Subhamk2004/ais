#include <bits/stdc++.h>
using namespace std;

class NQueensSolver {
private:
    int n;                      // Board size
    vector<int> board;     // Current solution, board[i] = column position of queen in row i
    int solutionCount;          // Count of solutions found
    bool printAllSolutions;     // Whether to print all solutions
    
    // Check if a queen can be placed at board[row] = col
    bool isSafe(int row, int col) const {
        for (int i = 0; i < row; i++) {
            // Check if there's a queen in the same column or diagonals
            if (board[i] == col || 
                board[i] - i == col - row || 
                board[i] + i == col + row) {
                return false;
            }
        }
        return true;
    }
    
    // Recursive backtracking with branch and bound
    void solveNQueensUtil(int row) {
        // Base case: All queens are placed
        if (row == n) {
            solutionCount++;
            if (printAllSolutions) {
                std::cout << "Solution " << solutionCount << ":\n";
                printSolution();
            }
            return;
        }
        
        // Try placing queen in each column of the current row
        for (int col = 0; col < n; col++) {
            // Branch and bound: Only proceed if placement is safe
            if (isSafe(row, col)) {
                // Place queen
                board[row] = col;
                
                // Recur to place rest of the queens
                solveNQueensUtil(row + 1);
                
                // Backtrack
                board[row] = -1;
            }
        }
    }
    
    // Print the current solution
    void printSolution() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i] == j) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
    
public:
    NQueensSolver(int boardSize, bool printAll = false) 
        : n(boardSize), board(boardSize, -1), solutionCount(0), printAllSolutions(printAll) {}
    
    int solve() {
        auto start = chrono::high_resolution_clock::now();
        
        solveNQueensUtil(0);
        
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = end - start;
        
        cout << "Found " << solutionCount << " solutions for " << n << "-queens problem.\n";
        cout << "Time taken: " << duration.count() << " milliseconds.\n";
        
        return solutionCount;
    }
};

int main() {
    cout << "N-Queens Solver using Branch and Bound with Backtracking\n";
    cout << "========================================================\n\n";
    
    // Example 1: 4-Queens problem
    cout << "Example 1: 4-Queens problem\n";
    NQueensSolver solver4(4, true);
    solver4.solve();
    cout << "\n";
    
    // Example 2: 8-Queens problem (only count solutions)
    cout << "Example 2: 8-Queens problem\n";
    NQueensSolver solver8(8, false);
    solver8.solve();
    cout << "\n";
    
    // Interactive mode
    int n;
    cout << "Enter board size for n-Queens problem (0 to exit): ";
    cin >> n;
    
    while (n > 0) {
        char printAll;
        cout << "Print all solutions? (y/n): ";
        cin >> printAll;
        
        NQueensSolver solver(n, printAll == 'y' || printAll == 'Y');
        solver.solve();
        
        cout << "\nEnter board size for n-Queens problem (0 to exit): ";
        cin >> n;
    }
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define vs vector<string>
#define vvs vector<vector<string>>
#define vi vector<int>


void solve(vvs& solutions,vs& board,int n,int col,vi& leftrow,vi& lowerdia, vi& upperdia){
    if(col==n){
    solutions.push_back(board);
    return;
    }
    
    for(int row=0;row<n;row++){
        if(leftrow[row]==0 && lowerdia[row+col]==0 && upperdia[(n-1)+(col-row)]==0){
        board[row][col]='Q';
        leftrow[row] =1;
        lowerdia[row+col]=1;
        upperdia[(n-1)+(col-row)]=1;
        solve(solutions,board,n,col+1,leftrow,lowerdia,upperdia);
        board[row][col]='.';
        leftrow[row] =0;
        lowerdia[row+col]=0;
        upperdia[(n-1)+(col-row)]=0;
        }
    }
}
int main(){
    cout<<"Enter the number of Queens:"<<endl;
    int n;cin>>n;
    vvs solutions;
    vs board(n,string(n,'.'));
    vi leftrow(n,0);
    vi lowerdia(2*n-1,0);
    vi upperdia(2*n-1,0);
    solve(solutions,board,n,0,leftrow,lowerdia,upperdia);
if(!solutions.empty()){
    for(auto board:solutions){
    for(auto row:board){
        cout<<row<<endl;
    }cout<<endl;
    }
}else {
    cout<<"No Solutions found";
}
    
    
}


// #include <iostream>
// #include <vector>
// using namespace std;

// // Function to solve the N-Queens problem using backtracking
// void solve(int col, int n, vector<string>& board, vector<vector<string>>& results,
//         vector<int>& leftRow, vector<int>& upperDiag, vector<int>& lowerDiag) {

//     if (col == n) {
//         results.push_back(board);
//         return;
//     }

//     for (int row = 0; row < n; row++) {
//         if (leftRow[row] == 0 && upperDiag[row + col] == 0 && lowerDiag[n - 1 + col - row] == 0) {
//             // Place queen
//             board[row][col] = 'Q';
//             leftRow[row] = upperDiag[row + col] = lowerDiag[n - 1 + col - row] = 1;

//             // Recur for next column
//             solve(col + 1, n, board, results, leftRow, upperDiag, lowerDiag);

//             // Backtrack
//             board[row][col] = '.';
//             leftRow[row] = upperDiag[row + col] = lowerDiag[n - 1 + col - row] = 0;
//         }
//     }
// }

// // Function to initiate board and start solving
// vector<vector<string>> solveNQueens(int n) {
//     vector<vector<string>> results;
//     vector<string> board(n, string(n, '.'));
//     vector<int> leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);

//     solve(0, n, board, results, leftRow, upperDiag, lowerDiag);
//     return results;
// }

// int main() {
//     int n;
//     cout << "Enter the value of N for N-Queens: ";
//     cin >> n;

//     vector<vector<string>> solutions = solveNQueens(n);

//     cout << "\nAll possible solutions:\n"<< endl;
//     if (solutions.empty()) {
//         cout << "No solutions exist for N = " << solutions.size() << endl;
//         return 0;
//     }
//     for (const auto& board : solutions) {
//         for (const string& row : board) {
//             cout << row << "\n";
//         }
//         cout << "---------\n";
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 20;
int N;
int board[MAX][MAX]; 
bool col[MAX], diag1[2 * MAX], diag2[2 * MAX]; 

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

void solve(int row) {
    if (row == N) {
        printSolution();
        return;
    }

    for (int c = 0; c < N; c++) {
        if (!col[c] && !diag1[row + c] && !diag2[row - c + N - 1]) {
            board[row][c] = 1;
            col[c] = diag1[row + c] = diag2[row - c + N - 1] = true;

            solve(row + 1); 

           
            board[row][c] = 0;
            col[c] = diag1[row + c] = diag2[row - c + N - 1] = false;
        }
    }
}

int main() {
    cout << "Enter number of queens (N): ";
    cin >> N;

    if (N <= 0 || N > MAX) {
        cout << "Invalid size.\n";
        return 1;
    }

    cout << "Solutions for " << N << "-Queens Problem:\n";
    solve(0);

    return 0;
}

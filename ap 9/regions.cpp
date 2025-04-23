#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size(), n = board[0].size();

        // Lambda function for DFS
        auto dfs = [&](int i, int j, auto&& dfs_ref) -> void {
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
            board[i][j] = '#'; // Temporarily mark the cell
            dfs_ref(i + 1, j, dfs_ref);
            dfs_ref(i - 1, j, dfs_ref);
            dfs_ref(i, j + 1, dfs_ref);
            dfs_ref(i, j - 1, dfs_ref);
        };

        // Start DFS from 'O's on the border
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(i, 0, dfs);
            if (board[i][n - 1] == 'O') dfs(i, n - 1, dfs);
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(0, j, dfs);
            if (board[m - 1][j] == 'O') dfs(m - 1, j, dfs);
        }

        // Flip surrounded 'O's to 'X' and revert '#' back to 'O'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    solution.solve(board);

    cout << "Modified Board:" << endl;
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << ' ';
        }
        cout << endl;
    }

    return 0;
}

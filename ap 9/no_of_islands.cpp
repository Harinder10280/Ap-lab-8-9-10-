#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Check for invalid indices and water cells
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
            return;

        // Mark the current cell as visited
        grid[i][j] = '2';

        // Explore all adjacent cells
        dfs(grid, i + 1, j); // Down
        dfs(grid, i - 1, j); // Up
        dfs(grid, i, j + 1); // Right
        dfs(grid, i, j - 1); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        // Traverse each cell in the grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // If a land cell is found, perform DFS
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++count; // Increment island count
                }
            }
        }

        return count;
    }
};

int main() {
    Solution solution;

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int result = solution.numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}

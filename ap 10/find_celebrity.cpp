#include <iostream>
#include <vector>

using namespace std;

// Simulated 'knows' API for demonstration purposes
vector<vector<int>> M; // Global matrix to represent 'knows' relationships

bool knows(int a, int b) {
    return M[a][b] == 1;
}

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        // Step 1: Find the candidate
        for (int i = 1; i < n; ++i) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }

        // Step 2: Verify the candidate
        for (int i = 0; i < n; ++i) {
            if (i == candidate) continue;
            if (knows(candidate, i) || !knows(i, candidate)) {
                return -1;
            }
        }
        return candidate;
    }
};

int main() {
    // Example matrix where M[i][j] == 1 means person i knows person j
    M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    Solution solution;
    int n = M.size();
    int celebrity = solution.findCelebrity(n);
    if (celebrity == -1) {
        cout << "No celebrity found." << endl;
    } else {
        cout << "Celebrity is person " << celebrity << "." << endl;
    }

    return 0;
}

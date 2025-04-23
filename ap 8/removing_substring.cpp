#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x > y)
            return removeSubstrings(s, 'a', 'b', x, y);
        else
            return removeSubstrings(s, 'b', 'a', y, x);
    }

private:
    int removeSubstrings(string s, char first, char second, int firstVal, int secondVal) {
        int total = 0;
        vector<char> stack;

        // First pass: remove substrings with higher value
        for (char c : s) {
            if (!stack.empty() && stack.back() == first && c == second) {
                stack.pop_back();
                total += firstVal;
            } else {
                stack.push_back(c);
            }
        }

        // Second pass: remove substrings with lower value
        vector<char> newStack;
        for (char c : stack) {
            if (!newStack.empty() && newStack.back() == second && c == first) {
                newStack.pop_back();
                total += secondVal;
            } else {
                newStack.push_back(c);
            }
        }

        return total;
    }
};

int main() {
    Solution solution;

    string s1 = "cdbcbbaaabab";
    int x1 = 4, y1 = 5;
    cout << "Maximum score (Example 1): " << solution.maximumGain(s1, x1, y1) << endl;

    string s2 = "aabbaaxybbaabb";
    int x2 = 5, y2 = 4;
    cout << "Maximum score (Example 2): " << solution.maximumGain(s2, x2, y2) << endl;

    return 0;
}

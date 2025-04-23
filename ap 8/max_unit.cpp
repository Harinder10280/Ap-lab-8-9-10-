#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Sort boxTypes in descending order based on units per box
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });

        int maxUnits = 0;
        for (const auto& box : boxTypes) {
            int boxesToLoad = min(truckSize, box[0]);
            maxUnits += boxesToLoad * box[1];
            truckSize -= boxesToLoad;
            if (truckSize == 0) break;
        }

        return maxUnits;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> boxTypes1 = {{1, 3}, {2, 2}, {3, 1}};
    int truckSize1 = 4;
    cout << "Maximum units (Example 1): " << solution.maximumUnits(boxTypes1, truckSize1) << endl;

    vector<vector<int>> boxTypes2 = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    int truckSize2 = 10;
    cout << "Maximum units (Example 2): " << solution.maximumUnits(boxTypes2, truckSize2) << endl;

    return 0;
}

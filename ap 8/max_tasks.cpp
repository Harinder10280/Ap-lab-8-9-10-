#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> taskSet(tasks.begin(), tasks.begin() + k);
        int m = workers.size();
        for (int i = k - 1; i >= 0; --i) {
            int workerStrength = workers[m - k + i];
            auto it = taskSet.upper_bound(workerStrength);
            if (it != taskSet.begin()) {
                --it;
                taskSet.erase(it);
            } else {
                if (pills == 0) return false;
                it = taskSet.upper_bound(workerStrength + strength);
                if (it == taskSet.begin()) return false;
                --it;
                taskSet.erase(it);
                --pills;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int left = 0, right = min(tasks.size(), workers.size());
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    Solution solution;
    vector<int> tasks = {3, 2, 1};
    vector<int> workers = {0, 3, 3};
    int pills = 1;
    int strength = 1;
    cout << "Maximum number of tasks that can be assigned: "
         << solution.maxTaskAssign(tasks, workers, pills, strength) << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord))
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();

            for (int i = 0; i < word.size(); ++i) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    temp[i] = c;
                    if (temp == endWord)
                        return level + 1;
                    if (wordSet.count(temp)) {
                        q.push({temp, level + 1});
                        wordSet.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};

int main() {
    Solution solution;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = solution.ladderLength(beginWord, endWord, wordList);
    cout << "Length of shortest transformation sequence: " << result << endl;

    return 0;
}

#include <iostream>
#include <cstdint>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n - 1); // Clears the least significant '1' bit
            ++count;
        }
        return count;
    }
};

int main() {
    Solution solution;
    uint32_t n = 11; // Binary: 00000000000000000000000000001011
    std::cout << "Number of 1 bits in " << n << " is: " << solution.hammingWeight(n) << std::endl;
    return 0;
}

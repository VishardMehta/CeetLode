class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n > 0) {
            // Check if the last bit is 1
            if (n & 1) {
                count++;
            }
            // Shift bits to the right by 1 to check the next bit
            n = n >> 1;
        }
        return count;
    }
};

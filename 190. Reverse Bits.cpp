class Solution {
public:
    int reverseBits(uint32_t n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            // Shift result to the left to make room for the next bit
            result = result << 1;
            // Add the last bit of n to result
            result = result | (n & 1);
            // Shift n to the right to process the next bit
            n = n >> 1;
        }
        return result;
    }
};

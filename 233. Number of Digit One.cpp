class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        long long i = 1; // Tracks the place value (1, 10, 100, etc.) Use long long to avoid overflow.
        
        while (i <= n) {
            long long high = n / (i * 10);
            long long curr = (n / i) % 10;
            long long low = n % i;
            
            // Apply the three conditional cases based on the current digit
            if (curr == 0) {
                count += high * i;
            } 
            else if (curr == 1) {
                count += (high * i) + low + 1;
            } 
            else {
                count += (high + 1) * i;
            }
            
            i *= 10; // Move to the next digit place value
        }
        
        return count;
    }
};

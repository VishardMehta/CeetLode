#include <unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> h(nums.begin(),nums.end());

        int max_streak = 0;
// Only looping over the set instead of the vector
        for (int num : h) { 
            if (h.find(num - 1) == h.end()) {
                int crr_num = num;   
                int streak = 1;

                while (h.find(crr_num + 1) != h.end()) {
                    crr_num += 1;     
                    streak += 1;
                }

                if (streak > max_streak) { 
                    max_streak = streak;
                }
            }
        }

        return max_streak;
    }
};

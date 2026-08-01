class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;   // chars currently inside [left, right)
        int left = 0, right = 0, maxLen = 0;

        while (right < s.length()) {
            if (!window.count(s[right])) {
                // s[right] is new — safe to grow the window
                window.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);  // record length before advancing
                right++;
            } else {
                // duplicate found — shrink from the left until it clears
                window.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int l = 0, maxFreq = 0, best = 0;

        for (int r = 0; r < s.length(); r++) {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);   // update using only the incoming char

            int windowLen = r - l + 1;
            if (windowLen - maxFreq > k) {
                freq[s[l]]--;
                l++;
                // deliberately NOT recalculating maxFreq here — it's allowed to be stale
            }

            best = max(best, r - l + 1);
        }
        return best;
    }
};

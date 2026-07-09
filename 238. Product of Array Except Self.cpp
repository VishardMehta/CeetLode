/* 
So compute two arrays: prefix[i] = product of everything strictly left of i, suffix[i] = product of everything strictly right of i. Multiply them.
Naively that's two extra arrays — O(n) space. The trick to hit O(1) extra space (output array doesn't count): build prefix products directly into the answer array first. Then walk backward, multiplying in the suffix product using a single running variable instead of a second array.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // pass 1: ans[i] = product of everything left of i
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        // pass 2: multiply in product of everything right of i
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};

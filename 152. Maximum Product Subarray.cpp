class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=nums[0], mini=nums[0], ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int x=nums[i];
            int prevmax= maxi;

            maxi=max({x, prevmax * x, mini * x});
            mini = min({x, prevmax * x, mini * x});

            ans = max(ans, maxi);
        }
        return ans;
    }
};

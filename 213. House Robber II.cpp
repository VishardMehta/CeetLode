class Solution {
public:
    int robline(vector<int>& nums,int start,int end){
        int prev2=0, prev1=0;

        for(int i=start;i<=end;i++){
            int curr=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
        
    }
     
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        int excludelast = robline(nums,0,n-2);
        int excludefirst = robline(nums,1,n-1);

        return max(excludefirst,excludelast);
    }
};

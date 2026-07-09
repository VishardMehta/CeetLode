class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;

        while(low<=high){

        int mid=low+ (high-low)/2;

        if(nums[mid]==target){
            return mid;
        }
            //left half is sorted , we go to right half to find the element

        if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<nums[mid]) high=mid-1;

            else low=mid+1;
        }
            // right half is sorted we got to left side to find the element and mid finds the element always 
        else{
            if( target<=nums[high] && nums[mid]<target) low=mid+1;

            else high=mid-1;
        }
    }
    return -1;
    }
};

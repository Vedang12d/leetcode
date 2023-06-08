class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(), low=0, high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=nums[0])
                low=mid+1;
            else
                high=mid-1;
        }
        low%=n;
        return nums[low];
    }
};
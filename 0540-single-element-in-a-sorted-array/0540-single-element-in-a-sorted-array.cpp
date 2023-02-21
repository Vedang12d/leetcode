class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()/2;
        while(low<high){
            int m=(low+high)/2;
            if(nums[2*m]!=nums[2*m+1])
                high=m;
            else
                low=m+1;
        }
        return nums[2*low];
    }
};
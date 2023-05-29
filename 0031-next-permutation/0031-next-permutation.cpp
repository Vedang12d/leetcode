class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),i=n-2;
        for(;i>=0;i--){
            if(nums[i]<nums[i+1])
                break;
        }
        if(i>=0){
            int j=n-1;
            for(;j>i and nums[j]<=nums[i];j--);
            swap(nums[j],nums[i]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};
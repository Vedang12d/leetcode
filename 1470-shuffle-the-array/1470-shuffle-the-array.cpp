class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i=n;i<2*n;i++)
            nums[i]=nums[i]<<10|nums[i-n];
        for(int i=0,j=n;j<2*n;i+=2,j++){
            nums[i]=nums[j]&1023;
            nums[i+1]=nums[j]>>10;
        }
        return nums;
    }
};
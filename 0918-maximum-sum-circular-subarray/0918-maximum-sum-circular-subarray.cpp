class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0,maxSum=nums[0],maxx=0,minSum=nums[0],minn=0;
        for(auto x:nums){
            maxx=max(maxx+x,x);
            maxSum=max(maxSum,maxx);
            minn=min(minn+x,x);
            minSum=min(minSum,minn);
            sum+=x;
        }
        return maxSum>0?max(maxSum,sum-minSum):maxSum;
    }
};
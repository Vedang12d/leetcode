class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int st=0,n=nums.size(),end=n-1;
        for(;st<n-1&&nums[st]<=nums[st+1];st++);
        for(;end>0&&nums[end]>=nums[end-1];end--);
        if(st>=end)
            return 0;
        int minn=INT_MAX,maxx=INT_MIN;
        for(int i=st;i<=end;i++){
            minn=min(minn,nums[i]);
            maxx=max(maxx,nums[i]);
        }
        for(;st>0&&minn<nums[st-1];)
            st--;
        for(;end<n-1&&maxx>nums[end+1];)
            end++;
        return end-st+1;
    }
};
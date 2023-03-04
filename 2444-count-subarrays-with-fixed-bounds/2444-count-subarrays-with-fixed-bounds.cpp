class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0,j=-1,k=-1,l=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK||nums[i]>maxK)
                j=k=l=i;
            if(nums[i]==minK)
                k=i;
            if(nums[i]==maxK)
                l=i;
            ans+=max(0LL,min(k,l)-j);
        }
        return ans;
    }
};
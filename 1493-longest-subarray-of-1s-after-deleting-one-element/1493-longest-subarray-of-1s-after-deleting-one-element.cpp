class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int j=0,i=0,k=0;j<n;j++){
            if(!nums[j])
                k++;
            while(k>1)
                if(!nums[i++])
                    k--;
            ans=max(ans,j-i);
        }
        return ans;
    }
};
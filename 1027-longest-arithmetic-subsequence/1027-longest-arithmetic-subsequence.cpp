class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans=2,n=nums.size();
        vector<unordered_map<int,int>> dp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int D=nums[j]-nums[i];
                dp[i][D]=1+(dp[j].count(D)?dp[j][D]:1);
                ans=max(ans,dp[i][D]);
            }
        }
        return ans;
    }
};
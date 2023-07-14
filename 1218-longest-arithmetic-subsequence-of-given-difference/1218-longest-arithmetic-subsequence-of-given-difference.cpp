class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int,int> dp;
        int ans=0;
        for(auto &x:arr){
            if(dp.count(x-d))
                dp[x]=dp[x-d]+1;
            else
                dp[x]=1;
            ans=max(ans,dp[x]);
        }
        return ans;
    }
};
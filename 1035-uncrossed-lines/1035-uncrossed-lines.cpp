class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i,int j,vector<int> &a,vector<int> &b){
        if(i>=a.size()||j>=b.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            return 1+dfs(i+1,j+1,a,b);
        return dp[i][j]=max(dfs(i+1,j,a,b),dfs(i,j+1,a,b));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(),vector<int>(nums2.size(),-1));
        return dfs(0,0,nums1,nums2);
    }
};
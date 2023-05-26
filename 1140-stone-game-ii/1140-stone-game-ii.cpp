class Solution {
public:
    vector<int> suff;
    vector<vector<int>> dp;
    int dfs(int i,int M,vector<int>& piles) {
        if(i>=piles.size())
            return 0;
        if(i+2*M>=piles.size()) 
            return suff[i];
        if(dp[i][M]!=-1)
            return dp[i][M];
        int mn=INT_MAX;
        for(int j=i+1;j<=i+2*M;j++)
            mn=min(mn,dfs(j,max(j-i,M),piles));
        return dp[i][M]=suff[i]-mn;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        suff.resize(n+1);
        dp.resize(n,vector<int>(n,-1));
        for(int i=n-1;i>=0;i--)
            suff[i]=suff[i+1]+piles[i];
        return dfs(0,1,piles);
    }
};
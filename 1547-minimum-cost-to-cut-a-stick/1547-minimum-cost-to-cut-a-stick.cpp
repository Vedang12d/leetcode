class Solution {
public:
    int m;
    vector<vector<int>> dp;
    // int dfs(int i,int j,vector<int> &cuts){
    //     if(j<=i+1)
    //         return 0;
    //     if(dp[i][j]!=INT_MAX)
    //         return dp[i][j];
    //     for(int k=i+1;k<j;k++)
    //         dp[i][j]=min(dp[i][j],cuts[j]-cuts[i]+dfs(i,k,cuts)+dfs(k,j,cuts));
    //     return dp[i][j];
    // }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        m=cuts.size();
        dp.resize(m,vector<int>(m));
        sort(cuts.begin(),cuts.end());
        for(int i=m-1;i>=0;i--){
            for(int j=i+1;j<m;j++){
                for(int k=i+1;k<j;k++)
                    dp[i][j]=min((!dp[i][j])?INT_MAX:dp[i][j],cuts[j]-cuts[i]+dp[i][k]+dp[k][j]);
            }
        }
        return dp[0][m-1];
    }
};
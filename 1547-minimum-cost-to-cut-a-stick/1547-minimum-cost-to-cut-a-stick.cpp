class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int m=cuts.size();
        vector<vector<int>> dp(m,vector<int>(m));
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
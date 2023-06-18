class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), mod=1e9+7;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<vector<int>> dir={{0,-1},{-1,0},{0,1},{1,0}};
        function<int(int,int)> dfs=[&](int i,int j){
            if(dp[i][j]!=-1)
                return dp[i][j];
            long long ans=1;
            for(auto &d:dir){
                int ni=i+d[0],nj=j+d[1];
                if(ni>=0 and ni<m and nj>=0 and nj<n and grid[ni][nj]>grid[i][j])
                    ans=(ans+dfs(ni,nj))%mod;
            }
            return dp[i][j]=ans;
        };
        long long ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                ans=(ans+dfs(i,j))%mod;
        return ans;
    }
};
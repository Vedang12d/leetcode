class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j){
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return grid[i][j];
        if(dp[i][j])
            return dp[i][j];
        if(i==grid.size()-1)
            return dp[i][j]=grid[i][j]+dfs(grid,dp,i,j+1);
        if(j==grid[0].size()-1)
            return dp[i][j]=grid[i][j]+dfs(grid,dp,i+1,j);
        return dp[i][j]=grid[i][j]+min(dfs(grid,dp,i+1,j),dfs(grid,dp,i,j+1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        return dfs(grid,dp,0,0);
    }
};
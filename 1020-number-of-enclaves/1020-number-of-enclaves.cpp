class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{-1,0},{1,0}};
    void dfse(vector<vector<int>>& grid,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||!grid[i][j])
            return;
        grid[i][j]=0;
        for(auto &d:dir)
            dfse(grid,i+d[0],j+d[1]);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(!i||!j||i==m-1||j==n-1&&grid[i][j])
                    dfse(grid,i,j);
        int ans=0;
        for(int i=0;i<m;i++)
            ans+=accumulate(grid[i].begin(),grid[i].end(),0);
        return ans;
    }
};
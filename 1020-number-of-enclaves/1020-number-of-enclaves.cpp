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
    int dfs(vector<vector<int>>& grid,int i,int j){
        grid[i][j]=0;
        int res=1;
        for(auto &d:dir){
            int ni=i+d[0],nj=j+d[1];
            if(grid[ni][nj])
                res+=dfs(grid,ni,nj);
        }
        return res;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(!i||!j||i==m-1||j==n-1&&grid[i][j])
                    dfse(grid,i,j);
        int ans=0;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++)
        //         cout<<grid[i][j]<<' ';
        //     cout<<'\n';
        // }
        // cout<<'\n'<<'\n';
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j])
                    ans+=dfs(grid,i,j);
            }
        }
        return ans;
    }
};
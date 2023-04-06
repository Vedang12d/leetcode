class Solution {
public:
    vector<vector<int>> dir={{0,-1},{0,1},{1,0},{-1,0}};
    bool dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size())
            return 0;
        if(grid[i][j])
            return 1;
        grid[i][j]=1;
        bool ok=1;
        for(auto &d:dir){
            if(!dfs(i+d[0],j+d[1],grid))
                ok=0;
        }
        return ok;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!grid[i][j])
                    ans+=dfs(i,j,grid);
            }
        }
        return ans;
    }
};
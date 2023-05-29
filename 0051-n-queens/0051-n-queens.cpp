class Solution {
public:
    int n;
    vector<vector<string>> ans;
    bool safe(vector<string> &grid,int i,int j){
        int ib=i,jb=j;
        while(i>=0 and j>=0)
            if(grid[i--][j--]=='Q')
                return 0;
        i=ib,j=jb;
        while(i>=0)
            if(grid[i--][j]=='Q')
                return 0;
        i=ib;
        while(j>=0)
            if(grid[i][j--]=='Q')
                return 0;
        j=jb;
        while(i>=0 and j<n)
            if(grid[i--][j++]=='Q')
                return 0;
        return 1;
    }
    void backtrack(vector<string> &grid, int i){
        if(i==n){
            ans.push_back(grid);
            return;
        }
        for(int j=0;j<n;j++){
            if(!safe(grid,i,j))
                continue;
            grid[i][j]='Q';
            backtrack(grid,i+1);
            grid[i][j]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        vector<string> grid(n,string(n,'.'));
        backtrack(grid,0);
        return ans;
    }
};
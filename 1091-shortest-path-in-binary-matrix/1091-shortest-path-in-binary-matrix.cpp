class Solution {
public:
    vector<vector<int>> dir={{0,-1},{0,1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
    int m,n;
    bool valid(int i,int j){
        return i>=0  and i<m and j>=0 and j<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        queue<array<int,2>> q;
        if(grid[0][0])
            return -1;
        if(m==1 and n==1)
            return 1;
        q.push({0,0});
        grid[0][0]=1;
        int ans=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [i,j]=q.front();
                q.pop();
                for(auto &d:dir){
                    int ni=i+d[0],nj=j+d[1];
                    if(valid(ni,nj) and !grid[ni][nj]){
                        if(ni==m-1 and nj==n-1)
                            return ans+1;
                        q.push({ni,nj});
                        grid[ni][nj]=1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
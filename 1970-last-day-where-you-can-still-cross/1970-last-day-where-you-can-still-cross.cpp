class Solution {
public:
    vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
    int r,c;
    bool solve(vector<vector<int>> &cells,int mid){
        vector<vector<int>> grid(r,vector<int>(c));
        for(int i=0;i<mid;i++)
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        queue<array<int,2>> q;
        for(int i=0;i<c;i++){
            if(!grid[0][i])
                q.push({0,i}), grid[0][i]=1;
        }
        while(!q.empty()){
            auto v=q.front();
            q.pop();
            if(v[0]==r-1)
                return 1;
            for(auto &d:dir){
                int ni=v[0]+d[0],nj=v[1]+d[1];
                if(ni<0||nj<0||ni>=r||nj>=c||grid[ni][nj])
                    continue;
                grid[ni][nj]=1;
                q.push({ni,nj});
            }
        }
        return 0;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n=cells.size();
        r=row,c=col;
        vector<vector<int>> grid(row,vector<int>(col));
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(cells,mid))
                low=mid+1;
            else
                high=mid-1;
        }
        return low-1;
    }
};
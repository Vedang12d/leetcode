class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0 and grid[i][j]<0;j--)
                ans++;
        }
        return ans;
    }
};
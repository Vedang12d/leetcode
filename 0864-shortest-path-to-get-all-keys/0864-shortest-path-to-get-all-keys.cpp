class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size(),n=grid[0].size(),keys=0,ans=0;
        unordered_map<char,int> mp;
        queue<vector<int>> q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(islower(grid[i][j])) keys++;
                if(grid[i][j]=='@') q.push({i,j,0});
            }
        set<vector<int>> vis;
        vector<array<int,2>> dir={{0,-1},{-1,0},{1,0},{0,1}};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto v=q.front();
                q.pop();
                int i=v[0],j=v[1],mask=v[2];
                if(__builtin_popcount(mask)==keys)
                    return ans;
                for(auto &d:dir){
                    int ni=i+d[0],nj=j+d[1],newMask=mask;
                    if(ni<0||ni>=m||nj<0||nj>=n||grid[ni][nj]=='#')
                        continue;
                    char ch=grid[ni][nj];
                    if(islower(ch))
                        newMask|=1<<(ch-'a');
                    if(vis.count({ni,nj,newMask}))
                        continue;
                    if(isupper(ch) and !(mask & (1<<(ch-'A'))))
                        continue;
                    q.push({ni,nj,newMask});
                    vis.insert({ni,nj,newMask});
                }
            }
            ans++;
        }
        return -1;
    }
};
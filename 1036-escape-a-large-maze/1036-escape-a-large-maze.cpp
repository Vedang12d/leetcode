class Solution {
public:
    bool dfs(int x, int y, vector<int>& tar, set<vector<int>> &vis, set<vector<int>> &block){
        if(x<0||x>=1000000||y<0||y>=1000000||block.count({x,y})||vis.count({x,y}))
            return 0;
        vis.insert({x,y});
        if(vis.size()>20000||(x==tar[0]&&y==tar[1]))
            return 1;
        return dfs(x+1,y,tar,vis,block)||dfs(x,y+1,tar,vis,block)||dfs(x-1,y,tar,vis,block)||dfs(x,y-1,tar,vis,block);
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<vector<int>> block(blocked.begin(),blocked.end()),vis1,vis2;
        return dfs(source[0],source[1],target,vis1,block)&&dfs(target[0],target[1],source,vis2,block);
    }
};
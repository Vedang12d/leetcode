class Solution {
public:
    bool valid(int u, bool color, vector<int>& colors, vector<vector<int>>& graph){
        if(colors[u]!=-1)
            return colors[u]==color;
        colors[u]=color;
        for(auto &v:graph[u]){
            if(!valid(v,!color,colors,graph))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colors(n,-1);
        for(int i=0;i<n;i++){
            if(colors[i]==-1 and !valid(i,true,colors,graph))
                return false;
        }
        return true;
    }
};
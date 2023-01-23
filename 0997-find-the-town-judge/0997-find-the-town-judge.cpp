class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> adj(n+1);
        for(auto e:trust){
            adj[e[1]]++;
            adj[e[0]]--;
        }
        for(int i=1;i<=n;i++)
            if(adj[i]==n-1)
                return i;
        return -1;
    }
};
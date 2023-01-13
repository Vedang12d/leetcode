class Solution {
public:
    int res=0;
    int dfs(vector<vector<int>> &adj,int i,string &s){
        int a=0,b=0;
        for(auto j:adj[i]){
            int cur=dfs(adj,j,s);
            if(s[i]==s[j])
                continue;
            if(cur>a&&cur>b){
                b=a;
                a=cur;
            }else if(cur>b)
                b=cur;
        }
        res=max(res,a+b+1);
        return a+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++)
            adj[parent[i]].push_back(i);
        dfs(adj,0,s);
        return res;
    }
};
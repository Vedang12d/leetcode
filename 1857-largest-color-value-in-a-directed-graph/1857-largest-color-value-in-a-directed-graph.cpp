class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size(),ans=0,nvis=n;
        vector<vector<int>> adj(n),col(n,vector<int>(26));
        vector<int> ind(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            ind[e[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ind[i])
                continue;
            q.push(i);
            col[i][colors[i]-'a']++;
        }
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            ans=max(ans,*max_element(col[u].begin(),col[u].end()));
            nvis--;
            for(auto &v:adj[u]){
                for(int i=0;i<26;i++)
                    col[v][i]=max(col[v][i],col[u][i]+(colors[v]-'a'==i));
                if(--ind[v])
                    continue;
                q.push(v);
            }
        }
        return !nvis?ans:-1;
    }
};
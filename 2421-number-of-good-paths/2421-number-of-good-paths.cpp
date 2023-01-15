class DSU
{
private:
    vector<int> parent, rank;
    int n;
public:
    DSU(int size)
    {
        n=size;
        parent.resize(size);
        rank.assign(size, 0);
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }
    int find_set(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = find_set(parent[x]);
    }
    void union_set(int x, int y)
    {
        int a = find_set(x), b = find_set(y);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size(),ans=0;
        vector<vector<int>> adj(n);
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
            mp[vals[i]].push_back(i);
        for(auto &e:edges){
            auto u=e[0],v=e[1];
            if(vals[u]>=vals[v])
                adj[u].push_back(v);
            else
                adj[v].push_back(u);
        }
        DSU dsu(n);
        for(auto &[a,v]:mp){
            for(auto u:v){
                for(auto v:adj[u])
                    dsu.union_set(u,v);
            }
            unordered_map<int,int> group;
            for(auto u:v)
                group[dsu.find_set(u)]++;
            ans+=v.size();
            for(auto [a,b]:group)
                ans+=(b*(b-1))/2;
        }
        return ans;
    }
};
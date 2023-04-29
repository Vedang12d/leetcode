class DSU
{
private:
    vector<int> parent, rank;

public:
    DSU(int size)
    {
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU uf(n);
        for(int i=0;i<queries.size();i++)
            queries[i].push_back(i);
        sort(queries.begin(),queries.end(),[](auto &l,auto &r){return l[2]<r[2];});
        sort(edgeList.begin(),edgeList.end(),[](auto &l,auto &r){return l[2]<r[2];});
        vector<bool> ans(queries.size());
        int i=0;
        for(auto &q:queries){
            while(i<edgeList.size()&&edgeList[i][2]<q[2])
                uf.union_set(edgeList[i][0],edgeList[i][1]), i++;
            if(uf.find_set(q[0])==uf.find_set(q[1]))
                ans[q[3]]=1;
        }
        return ans;
    }
};
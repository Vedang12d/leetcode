class DSU
{
public:
    vector<int> parent, size;
    int ans;
    DSU(int n)
    {
        parent.resize(n);
        ans=n;
        size.assign(n, 1);
        for (int i = 0; i < n; i++)
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
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            ans--;
            size[a] += size[b];
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DSU uf(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] and i!=j)
                    uf.union_set(i,j);
            }
        }
        return uf.ans;
    }
};
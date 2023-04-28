class DSU
{
private:
    vector<int> parent;

public:
    int size;
    DSU(int size)
    {
        parent.resize(size);
        this->size = size;
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
            parent[b] = a;
            size--;
        }
    }
};

class Solution {
public:
    bool similar(string &a,string &b){
        int ct=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i] and ++ct>2)
                return 0;
        }
        return 1;
    }
    int numSimilarGroups(vector<string>& strs) {
        DSU uf(strs.size());
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs.size();j++)
                if(similar(strs[i],strs[j]))
                    uf.union_set(i,j);
        }
        return uf.size;
    }
};
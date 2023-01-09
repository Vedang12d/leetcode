class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res=0;
        for(auto &p:points){
            unordered_map<int,int> mp;
            for(auto &q:points){
                if(p==q)
                    continue;
                mp[(p[0]-q[0])*(p[0]-q[0])+(p[1]-q[1])*(p[1]-q[1])]++;
            }
            for(auto &x:mp)
                res+=x.second*(x.second-1);
        }
        return res;
    }
};
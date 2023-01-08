class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double,int> mp;
        int ans=1;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                double a;
                if(points[i][0]==points[j][0])
                    a=DBL_MAX;
                else
                    a=(0.0+points[j][1]-points[i][1])/(0.0+points[j][0]-points[i][0]);
                mp[a]++;
                ans=max(ans,mp[a]+1);
            }
            mp.clear();
        }
        return ans;
    }
};
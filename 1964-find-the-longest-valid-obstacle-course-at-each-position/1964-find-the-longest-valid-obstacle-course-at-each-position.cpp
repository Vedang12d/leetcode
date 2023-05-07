class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> v(obstacles.size(),INT_MAX),ans;
        for(auto x:obstacles){
            auto ub=upper_bound(v.begin(),v.end(),x);
            ans.push_back(ub-v.begin()+1);
            *ub=x;
        }
        return ans;
    }
};
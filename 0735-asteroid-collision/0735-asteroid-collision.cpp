class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                ans.push_back(asteroids[i]);
                continue;
            }
            while(!ans.empty() and ans.back()>0 and ans.back()*-1>asteroids[i])
                ans.pop_back();
            if(ans.empty() or ans.back()<0)
                ans.push_back(asteroids[i]);
            else if(ans.back()*-1==asteroids[i])
                ans.pop_back();
        }
        return ans;
    }
};
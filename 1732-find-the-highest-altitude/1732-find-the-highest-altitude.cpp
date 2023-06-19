class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt=0,ans=0;
        for(auto &g:gain)
            alt+=g, ans=max(ans,alt);
        return ans;
    }
};
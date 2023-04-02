class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans(spells.size());
        for(int i=0;i<spells.size();i++){
            long long k=(success+spells[i]-1)/spells[i];
            ans[i]=potions.size()-(lower_bound(potions.begin(),potions.end(),k)-potions.begin());
        }
        return ans;
    }
};
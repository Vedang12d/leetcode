class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        vector<int> v(26,0),w(26,0);
        for(auto &ch:s)
            v[ch-'a']++;
        for(auto &ch:t)
            w[ch-'a']++;
        int ans=INT_MAX;
        for(auto &ch:t)
            ans=min(ans,v[ch-'a']/w[ch-'a']);
        return ans;
    }
};
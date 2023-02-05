class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())
            return {};
        vector<int> mp(26),np(26);
        for(auto ch:p)
            mp[ch-'a']++;
        int n=p.size(),j=0;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            if(i>=n){
                if(mp==np)
                    ans.push_back(j);
                np[s[j++]-'a']--;
            }
            np[s[i]-'a']++;            
        }
        if(mp==np)
            ans.push_back(j);
        return ans;
    }
};
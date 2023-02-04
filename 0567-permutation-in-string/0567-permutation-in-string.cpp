class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return 0;
        vector<int> mp(26,0),np(26,0);
        for(auto &x:s1)
            mp[x-'a']++;
        for(int i=0,j=0;i<s2.size();i++){
            np[s2[i]-'a']++;
            if(i-j==s1.size()-1 && mp==np)
                return 1;
            if(i-j>=s1.size()-1)
                np[s2[j++]-'a']--;
        }
        return 0;
    }
};
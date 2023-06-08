class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp,op;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i]) and mp[s[i]]!=t[i])
                return false;
            if(op.count(t[i]) and op[t[i]]!=s[i])
                return false;
            mp[s[i]]=t[i];
            op[t[i]]=s[i];
        }
        return true;
    }
};
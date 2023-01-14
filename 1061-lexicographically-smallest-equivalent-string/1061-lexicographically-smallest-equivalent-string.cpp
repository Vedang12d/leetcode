class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char> v(26);
        for(int i=0;i<26;i++)
            v[i]=static_cast<char>(97+i);
        for(int i=0;i<s1.size();i++){
            char maxx=max(v[s1[i]-'a'],v[s2[i]-'a']),minn=min(v[s1[i]-'a'],v[s2[i]-'a']);
            for(int i=0;i<26;i++)
                if(v[i]==maxx)
                    v[i]=minn;
        }
        for(auto &ch:baseStr)
            ch=v[ch-'a'];
        return baseStr;
    }
};
class Solution {
public:
    unordered_map<string,bool> map;
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return 1;
        string concat=s1+"/"+s2;
        if(map.count(concat))
            return map[concat];
        int n=s1.size();
        vector<int> mp(26);
        for(int i=0;i<n;i++){
            mp[s1[i]-'a']++;
            mp[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++)
            if(mp[i])
                return map[concat]=0;
        for(int i=1;i<n;i++){
            if((isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i)))||(isScramble(s1.substr(0,i),s2.substr(n-i))&&isScramble(s1.substr(i),s2.substr(0,n-i))))
                return map[concat]=1;
        }
        return map[concat]=0;
    }
};
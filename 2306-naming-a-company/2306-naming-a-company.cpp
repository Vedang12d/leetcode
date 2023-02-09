class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> v(26);
        long long ans=0;
        for(auto &s:ideas)
            v[s[0]-'a'].insert(s.substr(1));
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                long long a=0,b=0;
                for(auto &x:v[i])
                    if(!v[j].count(x))
                        a++;
                for(auto &x:v[j])
                    if(!v[i].count(x))
                        b++;
                ans+=a*b;
            }
        }
        return 2*ans;
    }
};
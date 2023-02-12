class Solution {
public:
    string dtob(long long num){
        string p;
        while(num){
            if(num&1)
                p+='1';
            else
                p+='0';
            num>>=1;
        }
        if(p.empty())
            p+='0';
        reverse(p.begin(),p.end());
        return p;
    }
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        unordered_map<string,pair<int,int>> mp;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(!mp.count("0"))
                    mp["0"]={i,i};
                continue;
            }
            string t;
            for(int j=i;j<min(i+33,(int)s.size());j++){
                t+=s[j];
                if(!mp.count(t))
                    mp[t]={i,j};
            }
        }
        for(auto q:queries){
            string t=dtob(q[0]^q[1]);
            if(!mp.count(t))
                ans.push_back({-1,-1});
            else
                ans.push_back({mp[t].first,mp[t].second});
        }
        return ans;
    }
};
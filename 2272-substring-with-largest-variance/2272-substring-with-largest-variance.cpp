class Solution {
public:
    int largestVariance(string s) {
        vector<int> mp(26);
        for(auto &ch:s)
            mp[ch-'a']++;
        int ans=0;
        for(int a=0;a<26;a++){
            for(int b=0;b<26;b++){
                int remA=mp[a], remB=mp[b];
                if(a==b || !remA || !remB)
                    continue;
                int curA=0,curB=0;
                for(auto &ch:s){
                    int c=ch-'a';
                    if(c==b)
                        curB++;
                    if(c==a)
                        curA++, remA--;
                    if(curA>0)
                        ans=max(ans,curB-curA);
                    if(curA>curB and remA>0)
                        curA=curB=0;
                }
            }
        }
        return ans;
    }
};
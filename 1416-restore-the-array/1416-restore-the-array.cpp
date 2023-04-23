class Solution {
public:
    vector<long long> dp;
    const int mod=1e9+7;
    int dfs(string &s,int i,int &k){
        if(i==s.size())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        long long num=0,res=0;
        for(int j=i;j<s.size();j++){
            num=num*10+(s[j]-'0');
            if(!num||num>k)
                break;
            res+=dfs(s,j+1,k);
            res%=mod;
        }
        return dp[i]=res;
    }
    int numberOfArrays(string s, int k) {
        dp.resize(s.size(),-1);
        return dfs(s,0,k);
    }
};
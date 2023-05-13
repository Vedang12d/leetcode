class Solution {
public:
    int mod=1e9+7,Z,O;
    vector<int> dp;
    int dfs(int i){
        if(!i)
            return 1;
        if(i<0)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=(dfs(i-Z)+dfs(i-O))%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        Z=zero, O=one;
        dp.resize(high+1,-1);
        int ans=0;
        for(int i=low;i<=high;i++)
            ans=(ans+dfs(i))%mod;
        return ans;
    }
};
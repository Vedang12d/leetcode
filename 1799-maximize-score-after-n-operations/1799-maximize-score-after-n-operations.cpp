class Solution {
public:
    vector<int> dp;
    int m;
    int dfs(int op,int mask,vector<int> &v){
        if(op>m/2)
            return 0;
        if(dp[mask])
            return dp[mask];
        for(int i=0;i<m;i++){
            if((mask>>i)&1)
                continue;
            for(int j=i+1;j<m;j++){
                if((mask>>j)&1)
                    continue;
                int newMask=(1<<i)|(1<<j)|mask;
                dp[mask]=max(dp[mask],op*gcd(v[i],v[j])+dfs(op+1,newMask,v));
            }
        }
        return dp[mask];
    }
    int maxScore(vector<int>& nums) {
        m=nums.size();
        dp.resize(1<<14);
        return dfs(1,0,nums);
    }
};
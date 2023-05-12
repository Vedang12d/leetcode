using ll=long long;
class Solution {
public:
    vector<ll> dp;
    ll dfs(int i,vector<vector<int>> &q){
        if(i>=q.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        ll pick=q[i][0]+dfs(i+q[i][1]+1,q), notpick=dfs(i+1,q);
        return dp[i]=max(pick,notpick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        dp.resize(questions.size(),-1);
        return dfs(0,questions);
    }
};
class Solution {
public:
    using ll=long long;
    vector<vector<ll>> dp;
    int n,end,mod=1e9+7;
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n=locations.size(),end=finish;
        dp.resize(n,vector<ll>(fuel+1,-1));
        return (int)dfs(locations,start,fuel);
    }
    ll dfs(vector<int> &locations, int cur, int fuel){
        if(fuel<0)
            return 0;
        if(dp[cur][fuel]!=-1)
            return dp[cur][fuel];
        ll ans=(cur==end);
        for(int next=0;next<n;next++){
            if(next==cur)
                continue;
            ans+=dfs(locations,next,fuel-(abs(locations[cur]-locations[next])));
            ans%=mod;
        }
        return dp[cur][fuel]=ans;
    }
};
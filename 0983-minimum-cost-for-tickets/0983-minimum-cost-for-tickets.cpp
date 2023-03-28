class Solution {
public:
    vector<int> dp;
    int rec(int i,vector<int> &days,vector<int> &costs){
        if(i>=days.size())
            return 0;
        if(dp[i])
            return dp[i];
        int j=lower_bound(days.begin(),days.end(),days[i]+1)-days.begin();
        int k=lower_bound(days.begin(),days.end(),days[i]+7)-days.begin();
        int l=lower_bound(days.begin(),days.end(),days[i]+30)-days.begin();
        return dp[i]=min(min(costs[0]+rec(j,days,costs),costs[1]+rec(k,days,costs)),costs[2]+rec(l,days,costs));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(366);
        return rec(0,days,costs);
    }
};
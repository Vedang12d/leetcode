class Solution {
public:
    vector<vector<int>> dp;
    int rec(vector<int>& sat,int i,int j=1){
        if(i==sat.size())
            return 0;
        if(dp[i][j]!=INT_MIN)
            return dp[i][j];
        int pick=sat[i]*j+rec(sat,i+1,j+1);
        int notpick=rec(sat,i+1,j);
        return dp[i][j]=max(pick,notpick);
    }
    int maxSatisfaction(vector<int>& sat) {
        dp.resize(sat.size(),vector<int>(sat.size()+1,INT_MIN));
        sort(sat.begin(),sat.end());
        return rec(sat,0);
    }
};
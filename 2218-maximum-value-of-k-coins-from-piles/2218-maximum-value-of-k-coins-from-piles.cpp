class Solution {
public:
    vector<vector<int>> dp;
    int solve(int ind,vector<vector<int>>& piles, int k){
        if(ind>=piles.size())
            return 0;
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        int mxi=solve(ind+1,piles,k),sum=0;
        for(int i=0;i<min(k,(int)piles[ind].size());i++){
            sum+=piles[ind][i];
            mxi=max(mxi,sum+solve(ind+1,piles,k-i-1));
        }
        return dp[ind][k]=mxi;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        dp.resize(piles.size(),vector<int>(k+1,-1));
        return solve(0,piles,k);
    }
};
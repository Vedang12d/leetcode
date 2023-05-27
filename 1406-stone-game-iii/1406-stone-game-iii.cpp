class Solution {
public:
    vector<int> dp;
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n+1,INT_MIN);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int sum=0;
            for(int j=i;j<min(n,i+3);j++){
                sum+=stoneValue[j];
                dp[i]=max(dp[i],sum-dp[j+1]);
            }
        }
        return (dp[0]>0?"Alice":(dp[0]<0)?"Bob":"Tie");
    }
};
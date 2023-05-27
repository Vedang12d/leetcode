class Solution {
public:
    vector<int> dp;
    int rec(int i, vector<int> &sv){
        if(i>=sv.size())
            return 0;
        if(dp[i]!=INT_MIN)
            return dp[i];
        int sum=0,val=INT_MIN;
        for(int j=i;j<i+3 and j<sv.size();j++){
            sum+=sv[j];
            dp[i]=max(dp[i],sum-rec(j+1,sv));
        }
        return dp[i];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        dp.resize(stoneValue.size(),INT_MIN);
        int val=rec(0,stoneValue);
        return (val>0?"Alice":(val<0)?"Bob":"Tie");
    }
};
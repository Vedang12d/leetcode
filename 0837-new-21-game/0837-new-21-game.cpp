class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(!k||n>=k+maxPts)
            return 1;
        vector<double> dp(n+1);
        dp[0]=1;
        double windowSum=1,ans=0;
        for(int i=1;i<=n;i++){
            dp[i]=windowSum/maxPts;
            if(i<k)
                windowSum+=dp[i];
            else
                ans+=dp[i];
            if(i>=maxPts)
                windowSum-=dp[i-maxPts];
        }
        return ans;
    }
};
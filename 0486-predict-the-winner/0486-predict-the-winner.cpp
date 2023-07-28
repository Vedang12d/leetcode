class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int k=0;k<n;k++){
            for(int i=0;i<n-k;i++){
                int j=i+k;
                if(i==j)
                    dp[i][j]=nums[i];
                else
                    dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        return dp[0].back()>=0;
    }
};
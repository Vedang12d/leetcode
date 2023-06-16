class Solution {
public:
    using ll=long long;
    vector<vector<ll>> dp;
    ll mod=1e9+7;
    ll dfs(vector<int> &nums){
        int n=nums.size(),ctr=0;
        if(n<=2)
            return 1;
        vector<int> left,right;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[0])
                left.push_back(nums[i]), ctr++;
            else
                right.push_back(nums[i]);
        }
        ll l=dfs(left), r=dfs(right);
        return ((dp[n-1][ctr]*l)%mod*r)%mod;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1);
        for(int i=0;i<=n;i++){
            dp[i].resize(i+1,1);
            for(int j=1;j<i;j++)
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
        return dfs(nums)-1;
    }
};
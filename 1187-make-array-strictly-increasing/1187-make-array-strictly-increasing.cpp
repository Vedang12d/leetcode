class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        vector<map<int,int>> dp(arr1.size());
        function<int(int,int)> dfs = [&](int ind, int k){
            if(ind==arr1.size())
                return 0;
            if(dp[ind].count(k))
                return dp[ind][k];
            int ans1,ans2;
            if(arr1[ind]>k)
                ans1=dfs(ind+1,arr1[ind]);
            else
                ans1=INT_MAX;
            auto it=upper_bound(arr2.begin(),arr2.end(),k);
            if(it==arr2.end())
                ans2=INT_MAX;
            else
                ans2=dfs(ind+1,*it);
            if(ans2!=INT_MAX)
                ans2++;
            return dp[ind][k]=min(ans1,ans2);
        };
        int ans=dfs(0,INT_MIN);
        return (ans!=INT_MAX?ans:-1);
    }
};
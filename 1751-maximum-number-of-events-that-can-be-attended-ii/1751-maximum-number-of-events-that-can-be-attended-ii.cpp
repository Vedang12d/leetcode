class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        function<int(int,int)> dfs=[&](int i,int k){
            if(!k||i==n)
                return 0;
            if(dp[i][k]!=-1)
                return dp[i][k];
            int low=i+1,high=n;
            while(low<high){
                int mid=(low+high)/2;
                if(events[mid][0]>events[i][1])
                    high=mid;
                else
                    low=mid+1;
            }
            return dp[i][k]=max(events[i][2]+dfs(low,k-1),dfs(i+1,k));
        };
        return dfs(0,k);
    }
};
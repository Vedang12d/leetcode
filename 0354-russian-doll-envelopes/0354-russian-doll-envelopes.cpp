class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int n=envelopes.size(),ans=0;
        vector<int> dp(n);
        for(auto &env:envelopes){
            int low=0,high=ans;
            while(low<high){
                int mid=(low+high)/2;
                (dp[mid]>=env[1])?high=mid:low=mid+1;
            }
            dp[low]=env[1];
            if(low==ans) ans++;
        }
        return ans;
    }
};
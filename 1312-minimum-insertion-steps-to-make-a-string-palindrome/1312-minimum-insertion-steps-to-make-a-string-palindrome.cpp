class Solution {
public:
    vector<vector<int>> dp;
    int lps(string &s,int l,int r){
        if(l==r)
            return 1;
        if(l>r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        if(s[l]==s[r])
            return 2+lps(s,l+1,r-1);
        return dp[l][r]=max(lps(s,l,r-1),lps(s,l+1,r));
    }
    int minInsertions(string s) {
        int n=s.size();
        dp.resize(n,vector<int>(n,-1));
        return n-lps(s,0,n-1);
    }
};
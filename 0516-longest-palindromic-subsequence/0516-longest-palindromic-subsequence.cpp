class Solution {
public:
    vector<vector<int>> dp;
    int bt(int l,int r,string &s){
        if(l==r)
            return 1;
        if(l>r)
            return 0;
        if(dp[l][r])
            return dp[l][r];
        if(s[l]==s[r])
            return dp[l][r]=2+bt(l+1,r-1,s);
        return dp[l][r]=max(bt(l+1,r,s),bt(l,r-1,s));
    }
    int longestPalindromeSubseq(string s) {
        dp.resize(s.size(),vector<int>(s.size()));
        return bt(0,s.size()-1,s);
    }
};
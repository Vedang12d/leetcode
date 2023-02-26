class Solution {
public:
    int match(string &s,string &t,vector<vector<int>> &dp,int i,int j){
        if(s.size()==i)
            return t.size()-j;
        if(t.size()==j)
            return s.size()-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]=match(s,t,dp,i+1,j+1);
        if(s[i]!=t[j]){
            dp[i][j]=min(dp[i][j],min(match(s,t,dp,i+1,j),match(s,t,dp,i,j+1)))+1;
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        if(!word1.size())
            return word2.size();
        if(!word2.size())
            return word1.size();
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return match(word1,word2,dp,0,0);
    }
};
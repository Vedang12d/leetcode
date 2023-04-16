class Solution {
public:
    vector<vector<int>> freq;
    vector<vector<int>> dp;
    int bt(string &t,int i,int j){
        if(i==t.size())
            return 1;
        if(j==freq.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        long long count=bt(t,i,j+1);
        count+=1LL*freq[j][t[i]-'a']*bt(t,i+1,j+1);
        return dp[i][j]=count%1000000007;
    }
    int numWays(vector<string>& words, string target) {
        dp.resize(target.size(),vector<int>(words[0].size(),-1));
        freq.resize(words[0].size(),vector<int>(26));
        for(auto &word:words)
            for(int i=0;i<word.size();i++)
                freq[i][word[i]-'a']++;
        return bt(target,0,0);
    }
};
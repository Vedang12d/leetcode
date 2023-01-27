class Solution {
public:
    bool possible(string &word, unordered_set<string> &st){
        int n=word.size();
        bitset<31> dp;
        dp[n]=1;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[n-j]&&st.count(word.substr(j,i-j))){
                    dp[n-i]=1;
                    break;
                }
            }
        }
        return dp[0];
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st;
        vector<string> ans;
        sort(words.begin(),words.end(),[&](string s, string t){return s.size()<t.size();});
        for(auto &word:words){
            if(possible(word,st))
                ans.push_back(word);
            st.insert(word);
        }
        return ans;
    }
};
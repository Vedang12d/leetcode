class Solution {
public:
    bool isPal(string &s,int l,int r){
        for(;l<r;l++,r--)
            if(s[l]!=s[r])
                return 0;
        return 1;
    }
    void backtrack(vector<vector<string>> &ans,vector<string> &cur,string &s,int l=0){
        if(!cur.empty() && l>=s.size())
            ans.push_back(cur);
        for(int i=l;i<s.size();i++){
            if(!isPal(s,l,i))
                continue;
            if(l==i)
                cur.push_back(string(1,s[i]));
            else
                cur.push_back(s.substr(l,i+1-l));
            backtrack(ans,cur,s,i+1);
            cur.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        backtrack(ans,cur,s);
        return ans;
    }
};
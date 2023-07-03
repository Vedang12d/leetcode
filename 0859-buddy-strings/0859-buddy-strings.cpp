class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        vector<int> a(26),b(26);
        for(auto &ch:s)
            a[ch-'a']++;
        for(auto &ch:goal)
            b[ch-'a']++;
        if(s==goal){
            for(int i=0;i<26;i++)
                if(a[i]>1)
                    return true;
            return false;
        }
        int ct=0,bi;
        for(int i=0;i<s.size();i++){
            if(s[i]==goal[i])
                continue;
            if(!ct)
                bi=i;
            else if(ct==1)
                swap(s[i],s[bi]);
            else
                return false;
            ct++;
        }
        // cout<<d<<' '<<ct<<'\n';
        return s==goal;
    }
};
class Solution {
public:
    string simplifyPath(string path) {
        string ans,s;
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss,s,'/')){
            if(s.empty()||s==".")
                continue;
            if(s==".."){
                if(!stk.empty())
                    stk.pop_back();
            }else
                stk.push_back(s);
        }
        if(stk.empty())
            stk.push_back("");
        for(auto x:stk)
            ans+="/"+x;
        return ans;
    }
};
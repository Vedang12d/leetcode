class Solution {
public:
    void bt(vector<string> &ans,string cur,string &s,int ct,int id){
        if(ct==4&&id==s.size())
            {ans.push_back(cur); return;}
        string t;
        t+=s[id];
        for(int i=id+1;i<=s.size()&&i<=id+3;i++){
            if(((t.size()>1&&t[0]!='0')||(t.size()==1))&&stoi(t)<256)
                bt(ans,(!ct)?t:cur+"."+t,s,ct+1,i);
            t+=s[i];
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.size()>12)
            return ans;
        bt(ans,"",s,0,0);
        return ans;
    }
};
class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int cts=count(s.begin(),s.end(),'1'),ctt=count(t.begin(),t.end(),'1');
        if((cts>0)^(ctt>0))
            return false;
        return true;
    }
};
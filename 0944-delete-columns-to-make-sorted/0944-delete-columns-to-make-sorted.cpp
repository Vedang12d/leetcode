class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ct=0;
        for(int i=0;i<strs[0].size();i++){
            string s;
            for(int j=0;j<strs.size();j++)
                s+=strs[j][i];
            if(!is_sorted(s.begin(),s.end()))
                ct++;
        }
        return ct;
    }
};
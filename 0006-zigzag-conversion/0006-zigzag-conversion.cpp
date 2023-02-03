class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows);
        int n=s.size();
        for(int i=0;i<n;){
            for(int j=0;j<numRows && i<n;j++)
                v[j]+=s[i++];
            for(int j=numRows-2;j>=1 && i<n;j--)
                v[j]+=s[i++];
        }
        return accumulate(v.begin(), v.end(), string{});
    }
};
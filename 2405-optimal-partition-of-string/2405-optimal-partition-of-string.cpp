class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int ans=1;
        for(auto &ch:s){
            if(!st.count(ch))
                st.insert(ch);
            else{
                st.clear();
                ans++;
                st.insert(ch);
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(auto &ch:s){
            if(!st.empty()){
                if(ch=='}'&&st.top()=='{')
                    st.pop();
                else if(ch==')'&&st.top()=='(')
                    st.pop();
                else if(ch==']'&&st.top()=='[')
                    st.pop();
                else
                    st.push(ch);
            }
            else
                st.push(ch);
        }
        return st.empty();
    }
};
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        string t;
        int ans=s.size(),mx=0;
        for(int i=0;i<s.size();){
            if(!t.empty()&&s.substr(i,t.size())==t){
                mx=max(mx,(int)t.size());
                int m=t.size();
                t+=s.substr(i,t.size());
                i+=m;
                continue;
            }
            t+=s[i++];
        }
        if(mx)
            ans-=mx-1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends
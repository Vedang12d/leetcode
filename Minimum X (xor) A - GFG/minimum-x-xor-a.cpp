//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int noa=__builtin_popcount(a),nob=__builtin_popcount(b);
        if(noa==nob)
            return a;
        else if(noa<nob){
            string s=bitset<64>(a).to_string().substr(64-(int)log2(a)-1);
            for(int i=s.size()-1,ct=nob-noa;i>=0;i--){
                if(s[i]=='1')
                    s[i]='0';
                else if(s[i]=='0'&&ct)
                    s[i]='1', ct--;
            }
            return (stoi(s,0,2))^a;
        }
        else{
            string s=bitset<64>(a).to_string().substr(64-(int)log2(a)-1);
            for(int i=0,ct=nob;i<s.size()&&ct;i++)
                if(s[i]=='1')
                    s[i]='0', ct--;
            return (stoi(s,0,2))^a;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
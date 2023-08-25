//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char,int> mp;
        int n=s.size();
        int ans=-1;
        for(int j=0,i=0;i<n;i++){
            mp[s[i]]++;
            while(mp.size()>k){
                if(--mp[s[j]]==0)
                    mp.erase(s[j]);
                j++;
            }
            if(mp.size()==k)
                ans=max(ans,i-j+1);
        }
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
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
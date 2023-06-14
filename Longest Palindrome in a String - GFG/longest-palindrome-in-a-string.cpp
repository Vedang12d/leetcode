//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        int n=s.size();
        string ans;
        for(int i=0;i<n;i++){
            int left=i,right=i;
            while(left>=0 and s[left]==s[i])
                left--;
            while(right<n and s[right]==s[i])
                right++;
            while(left>=0 and right<n and s[left]==s[right])
                left--, right++;
            if(right-left-1>ans.size())
                ans=s.substr(left+1,right-left-1);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
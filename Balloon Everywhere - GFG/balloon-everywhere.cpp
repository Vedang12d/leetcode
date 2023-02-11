//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        vector<int> a(26),b(26);
        string t="balloon";
        for(auto &ch:s)
            a[ch-'a']++;
        for(auto &ch:t)
            b[ch-'a']++;
        int ans=INT_MAX;
        for(int i=0;i<26;i++)
            if(b[i])
                ans=min(ans,a[i]/b[i]);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
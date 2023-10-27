//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    vector<vector<int>> dp;
    int rec(int i,int j,string &s){
        if(i==j)
            return 1;
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==s[j])
            return dp[i][j]=2+rec(i+1,j-1,s);
        return dp[i][j]=max(rec(i+1,j,s),rec(i,j-1,s));
    }
    int minimumNumberOfDeletions(string S) { 
        int n=S.size();
        dp.resize(n,vector<int>(n,-1));
        return n-rec(0,n-1,S);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends
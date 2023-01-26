//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	const int mod=1e9+7;
    vector<int> dp;
    string s;
    int n;
    int bt(int i){
        if(i>=n)
            return 1;
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=bt(i+1);
        if(i+1<n){
            int num=(s[i]-'0')*10+(s[i+1]-'0');
            if(num<=26)
                ans+=bt(i+2);
        }
        return dp[i]=ans%mod;
    }
	int CountWays(string str){
	    n=str.size();
	    s=str;
	    dp.assign(n+1,-1);
	    return bt(0);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
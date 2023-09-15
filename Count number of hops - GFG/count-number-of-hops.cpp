//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        int mod=1e9+7;
        vector<long long> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            long long x=0;
            if(i-1>=0)
                x+=dp[i-1];
            if(i-2>=0)
                x+=dp[i-2];
            if(i-3>=0)
                x+=dp[i-3];
            x%=mod;
            dp[i]=x;
        }
        return dp[n];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends
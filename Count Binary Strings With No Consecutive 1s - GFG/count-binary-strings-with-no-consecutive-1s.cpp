//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    const int mod=1e9+7;
    unordered_map<long long,long long> mp;
    long long fib(long long n){
        if(mp.count(n))
            return mp[n];
        long long k=n/2;
        if(n&1)
            return mp[n]=(fib(k)*fib(k+1)+fib(k-1)*fib(k))%mod;
        return mp[n]=(fib(k)*fib(k)+fib(k-1)*fib(k-1))%mod;
    }
    int countStrings(long long int N) {
        mp[0]=mp[1]=1;
        return fib(N+1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends
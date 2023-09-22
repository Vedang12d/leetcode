//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        vector<long long> pref(n),suff(n);
        for(int i=1;i<n;i++)
            pref[i]=pref[i-1]+a[i-1];
        for(int i=n-2;i>=0;i--)
            suff[i]=suff[i+1]+a[i+1];
        for(int i=0;i<n;i++)
            if(pref[i]==suff[i])
                return i+1;
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
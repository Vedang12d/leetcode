//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    int prev=0,ct=0;
    for(int i=0;i<n-1;i++){
        if(price[i+1]>=price[i])
            continue;
        if(i!=prev){
            ct++;
            cout<<'('<<prev<<' '<<i<<") ";
        }
        prev=i+1;
    }
    if(prev!=n-1){
        ct++;
        cout<<'('<<prev<<' '<<n-1<<") ";
    }
    if(!ct)
        cout<<"No Profit";
    cout<<endl;
}
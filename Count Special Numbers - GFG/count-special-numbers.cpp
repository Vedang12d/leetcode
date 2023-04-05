//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> factors(int n){
        vector<int> v;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(n/i!=i)
                    v.push_back(n/i);
                v.push_back(i);
            }
        }
        return v;
    }
    int countSpecialNumbers(int N, vector<int> arr) {
        int ans=0;
        unordered_map<int,int> mp;
        for(auto &i:arr)
            mp[i]++;
        for(int i=0;i<N;i++){
            mp[arr[i]]--;
            vector<int> v=factors(arr[i]);
            for(auto &j:v){
                if(mp[j]){
                    ans++;
                    break;
                }
            }
            mp[arr[i]]++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
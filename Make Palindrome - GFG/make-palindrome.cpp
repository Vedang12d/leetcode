//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        unordered_map<string,int> mp;
        for(auto &s:arr){
            string t=s;
            reverse(t.begin(),t.end());
            if(mp.count(t)){
                if(--mp[t]==0)
                    mp.erase(t);
            }else{
                mp[s]++;
                // cout<<s<<' ';
            }
        }
        if(mp.empty())
            return 1;
        else if(mp.size()>1)
            return 0;
        else{
            string s=mp.begin()->first;
            string t=s;
            reverse(t.begin(),t.end());
            return t==s;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends
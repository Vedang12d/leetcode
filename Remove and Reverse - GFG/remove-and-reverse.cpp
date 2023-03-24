//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        int n=s.size();
        vector<bool> del(n);
        vector<int> mp(26);
        for(auto &ch:s)
            mp[ch-'a']++;
        bool rev=0;
        for(int i=0,j=n-1;i<j;){
            if(!rev){
                if(mp[s[i]-'a']>1){
                    mp[s[i]-'a']--;
                    del[i]=1;
                    rev=!rev;
                }
                i++;
            }else{
                if(mp[s[j]-'a']>1){
                    mp[s[j]-'a']--;
                    del[j]=1;
                    rev=!rev;
                }
                j--;
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            if(!del[i])
                ans+=s[i];
        }
        if(rev)
            reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
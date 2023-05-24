//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

using ll=long long;
class Solution {
  public:
    vector<string> ans;
    string S;
    int target;
    void backtrack(string path,int i,ll eval,ll mul){
        if(i==S.size()){
            if(target==eval)
                ans.push_back(path);
            return;
        }
        for(int j=i;j<S.size();j++){
            if(j>i and S[i]=='0')
                break;
            ll cur=0;
            for(int k=i;k<=j;k++)
                cur=cur*10+(S[k]-'0');
            if(!i){
                backtrack(path+to_string(cur),j+1,cur,cur);
                continue;
            }
            backtrack(path+"+"+to_string(cur),j+1,eval+cur,cur);
            backtrack(path+"-"+to_string(cur),j+1,eval-cur,-cur);
            backtrack(path+"*"+to_string(cur),j+1,eval-mul+mul*cur,mul*cur);
        }
    }
    vector<string> addOperators(string S, int target) {
        this->S=S;
        this->target=target;
        backtrack("",0,0,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
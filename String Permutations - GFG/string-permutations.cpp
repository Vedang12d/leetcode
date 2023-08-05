//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void backtrack(vector<string> &ans,vector<bool> &vis,string &t,string &s){
        if(t.size()==s.size()){
            ans.push_back(t);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(vis[i])
                continue;
            t+=s[i];
            vis[i]=1;
            backtrack(ans,vis,t,s);
            t.pop_back();
            vis[i]=0;
        }
    }
    
    vector<string> permutation(string S)
    {
        vector<string> ans;
        int n=S.size();
        vector<bool> vis(n);
        string t;
        backtrack(ans,vis,t,S);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends
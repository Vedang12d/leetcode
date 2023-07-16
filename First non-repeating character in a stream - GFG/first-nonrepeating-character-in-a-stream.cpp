//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    int n=A.size();
		    string ans;
		    queue<char> q;
		    vector<int> vis(26);
		    for(auto &ch:A){
		        if(q.empty()||!vis[ch-'a'])
		            q.push(ch);
		        vis[ch-'a']++;
		        while(!q.empty() and vis[q.front()-'a']>1)
		            q.pop();
		        ans+=(q.empty())?'#':q.front();
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
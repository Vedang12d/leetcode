//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& mat) {
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1},{-1,1},{-1,-1},{1,-1},{1,1}};
        int m=mat.size(),n=mat[0].size(),ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!mat[i][j])
                    continue;
                int ct=0;
                for(auto &d:dir){
                    int ni=i+d.first,nj=j+d.second;
                    if(ni<0 or nj<0 or ni>=m or nj>=n)
                        continue;
                    if(!mat[ni][nj])
                        ct++;
                }
                if(ct and ct%2==0)
                    ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
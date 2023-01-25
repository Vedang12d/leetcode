//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string s,t;
        for(auto &x:str){
            if(isupper(x))
                s+=x;
            else
                t+=x;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0,j=0;
        for(auto &x:str){
            if(islower(x))
                x=t[i++];
            else
                x=s[j++];
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newinter) {
        vector<vector<int>> ans;
        int n=inter.size(),i=0;
        while(i<n&&newinter[0]>inter[i][1])
            ans.push_back(inter[i++]);
        while(i<n&&newinter[1]>=inter[i][0]){
            newinter[0]=min(newinter[0],inter[i][0]);
            newinter[1]=max(newinter[1],inter[i++][1]);
        }
        ans.push_back(newinter);
        while(i<n)
            ans.push_back(inter[i++]);
        return ans;
    }
};
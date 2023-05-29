class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
        vector<vector<int>> ans;
        int n=inter.size();
        for(int i=0;i<n;){
            int prev=inter[i][1],j=i+1;
            while(j<n and inter[j][0]<=prev)
                prev=max(prev,inter[j++][1]);
            ans.push_back({inter[i][0],prev});
            i=j;
        }
        return ans;
    }
};
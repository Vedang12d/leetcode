class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        vector<int> ans;
        vector<vector<int>> freq(n+1);
        for(auto &x:nums)
            mp[x]++;
        for(auto &it:mp)
            freq[it.second].push_back(it.first);
        for(int i=n;i>=0 and ans.size()<k;i--){
            for(auto &x:freq[i])
                ans.push_back(x);
        }
        return ans;
    }
};
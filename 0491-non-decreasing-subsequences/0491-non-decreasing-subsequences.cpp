class Solution {
public:
    void dfs(vector<vector<int>> &ans,vector<int> &v,vector<int> &nums,int i){
        if(v.size()>1)
            ans.push_back(v);
        unordered_set<int> st;
        for(int j=i;j<nums.size();j++){
            if((v.empty()||v.back()<=nums[j])&&!st.count(nums[j])){
                v.push_back(nums[j]);
                dfs(ans,v,nums,j+1);
                v.pop_back();
                st.insert(nums[j]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        dfs(ans,v,nums,0);
        return ans;
    }    
};
class Solution {
public:
    vector<int> ans,dp;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dp.resize(nums.size()+1,-1);
        vector<int> temp;
        solve(nums,0,1,temp);
        return ans;
    }
    void solve(vector<int> &nums,int i,int prev,vector<int> &temp){
        if(i>=nums.size()){
            if(temp.size()>ans.size())
                ans=temp;
            return;
        }
        if((int)temp.size()>dp[i]&&nums[i]%prev==0){
            dp[i]=temp.size();
            temp.push_back(nums[i]);
            solve(nums,i+1,nums[i],temp);
            temp.pop_back();
        }
        solve(nums,i+1,prev,temp);
    }
};
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            for(;j<nums.size() and nums[j]==nums[j-1]+1;j++);
            j--;
            if(i==j)
                ans.push_back(to_string(nums[i]));
            else
                ans.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
            i=j;
        }
        return ans;
    }
};
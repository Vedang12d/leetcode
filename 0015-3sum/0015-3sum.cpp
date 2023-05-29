class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            for(;j<k;){
                if(nums[j]+nums[k]+nums[i]==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k and nums[j+1]==nums[j])
                        j++;
                    j++;
                    while(j<k and nums[k-1]==nums[k])
                        k--;
                    k--;
                }else if(nums[j]+nums[k]+nums[i]>0)
                    k--;
                else
                    j++;
            }
            while(i<n-1 and nums[i+1]==nums[i])
                i++;
        }
        return ans;
    }
};
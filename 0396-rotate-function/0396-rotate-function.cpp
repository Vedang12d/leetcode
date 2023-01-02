class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size(),sum=0,F=0;
        for(int i=0;i<n;i++){
            F+=i*nums[i];
            sum+=nums[i];
        }
        int res=F;
        for(int i=n-1;i>=0;i--){
            F+=sum-n*nums[i];
            res=max(res,F);
        }
        return res;
    }
};
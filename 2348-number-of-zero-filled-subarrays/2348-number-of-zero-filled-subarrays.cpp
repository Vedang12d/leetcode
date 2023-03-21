class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int ct=0;
        long long ans=0;
        for(auto &x:nums){
            if(!x){
                ct++;
            }else{
                ans+=(1LL*ct*(ct+1))/2;
                ct=0;
            }
        }
        ans+=(1LL*ct*(ct+1))/2;
        ct=0;
        return ans;
    }
};
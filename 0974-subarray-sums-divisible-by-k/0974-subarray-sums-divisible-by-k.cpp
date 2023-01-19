class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;
        int ans=0,sum=0;
        for(auto x:nums){
            sum+=x;
            sum%=k;
            if(sum<0){
                sum*=-1;
                sum=k-sum;
            }
            ans+=mp[sum]++;
        }
        return ans;
    }
};
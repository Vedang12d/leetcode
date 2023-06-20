class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n,-1);
        vector<long long> pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++)
            pref[i]=pref[i-1]+nums[i];
        for(int i=0;i<n;i++){
            if(i-k>=0 and i+k<n)
                ans[i]=(0LL+pref[i+k]-pref[i-k]+nums[i-k])/(2*k+1LL);
        }
        return ans;
    }
};
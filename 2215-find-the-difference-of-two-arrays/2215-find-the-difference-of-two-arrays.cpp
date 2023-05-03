class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(),nums1.end()),st2(nums2.begin(),nums2.end());
        vector<vector<int>> ans(2);
        for(int i=0;i<max(nums1.size(),nums2.size());i++){
            if(i<nums1.size()and!st2.count(nums1[i]))
                ans[0].push_back(nums1[i]),st2.insert(nums1[i]);
            if(i<nums2.size()and!st1.count(nums2[i]))
                ans[1].push_back(nums2[i]),st1.insert(nums2[i]);
        }
        return ans;
    }
};
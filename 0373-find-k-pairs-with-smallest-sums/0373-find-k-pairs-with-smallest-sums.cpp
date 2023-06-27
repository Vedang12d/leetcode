class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        auto comp = [&](vector<int> &a,vector<int> &b) {
            return nums1[a[0]]+nums2[a[1]]>nums1[b[0]]+nums2[b[1]];
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(comp)> pq(comp);
        pq.push({0,0});
        while(k-- and pq.size()){
            auto top=pq.top();
            pq.pop();
            ans.push_back({nums1[top[0]],nums2[top[1]]});
            if(top[0]+1<nums1.size())
                pq.push({top[0]+1,top[1]});
            if(top[0]==0 and top[1]+1<nums2.size())
                pq.push({top[0],top[1]+1});
        }
        return ans;
    }
};
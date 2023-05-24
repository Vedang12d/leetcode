class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<array<int,2>> v;
        for(int i=0;i<nums1.size();i++)
            v.push_back({nums2[i],nums1[i]});
        sort(v.rbegin(),v.rend());
        long long sum=0,ans=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto &[x,y]:v){
            pq.push(y);
            sum+=y;
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
                ans=max(ans,sum*x);
        }
        return ans;
    }
};
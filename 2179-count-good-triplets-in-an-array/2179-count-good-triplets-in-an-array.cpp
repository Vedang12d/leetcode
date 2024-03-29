#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set=tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> pref(n),suff(n),pos(n);
        for(int i=0;i<n;i++)
            pos[nums2[i]]=i;
        ordered_set s;
        for(int i=0;i<n;i++){
            pref[i]=s.order_of_key(pos[nums1[i]]);
            s.insert(pos[nums1[i]]);
        }
        s.clear();
        for(int i=n-1;i>=0;i--){
            suff[i]=s.order_of_key(-pos[nums1[i]]);
            s.insert(-pos[nums1[i]]);
        }
        long long ans=0;
        for(int i=1;i<n-1;i++)
            ans+=1LL*pref[i]*suff[i];
        return ans;
    }
};
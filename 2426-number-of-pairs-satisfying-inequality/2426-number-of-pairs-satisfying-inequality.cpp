#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;  
using ordered_set=tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>;
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        ordered_set st;
        long long ans=0;
        for(int i=0;i<nums1.size();i++){
            ans+=st.order_of_key(nums1[i]-nums2[i]+diff+1);
            st.insert(nums1[i]-nums2[i]);
        }
        return ans;
    }
};
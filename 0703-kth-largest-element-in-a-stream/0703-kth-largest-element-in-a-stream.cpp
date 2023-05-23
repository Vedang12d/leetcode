#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using oset=tree<T,null_type,greater_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
class KthLargest {
public:
    oset<int> st;
    int k;
    KthLargest(int k, vector<int>& nums) {
        for(auto &x:nums)
            st.insert(x);
        this->k=k;
    }
    
    int add(int val) {
        st.insert(val);
        return *(st.find_by_order(k-1));
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using oset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp,path;
        vector<int> lis;
        for(auto &x:nums){
            int i=lower_bound(lis.begin(),lis.end(),x)-lis.begin(),k=1;
            if(i){
                int j=dp[i-1].rend()-lower_bound(dp[i-1].rbegin(),dp[i-1].rend(),x);
                k=path[i-1].back()-path[i-1][j];
            }
            if(i==dp.size())
                dp.push_back({});
            dp[i].push_back(x);
            if(i==lis.size()){
                lis.push_back(x);
                path.push_back({0,k});
            }else{
                lis[i]=x;
                path[i].push_back(path[i].back()+k);
            }
        }
        return path.back().back();
    }
};
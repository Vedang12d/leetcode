class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int high=accumulate(weights.begin(),weights.end(),0),low=max(high/days,*max_element(weights.begin(),weights.end()));
        while(low<high){
            int mid=(low+high)/2;
            int cur=0,res=1;
            for(int weight:weights){
                cur+=weight;
                if(cur>mid)
                    cur=weight, res++;
            }
            if(res<=days)
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};
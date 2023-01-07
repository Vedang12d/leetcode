class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(cost.begin(),cost.end(),0)>accumulate(gas.begin(),gas.end(),0))
            return -1;
        int ans=0,sum=0;
        for(int i=0;i<cost.size();i++){
            sum+=gas[i]-cost[i];
            if(sum<0){
                ans=i+1;
                sum=0;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold=INT_MIN,empty=0;
        for(auto p:prices){
            hold=max(hold,empty-p);
            empty=max(empty,hold+p-fee);
        }
        return empty;
    }
};
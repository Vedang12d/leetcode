class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),ans=0;
        prices.push_back(-1);
        for(int i=0;i<n;){
            int j=i;
            while(j<n and prices[j]<prices[j+1])
                j++;
            ans+=prices[j]-prices[i];
            i=j+1;
        }
        return ans;
    }
};
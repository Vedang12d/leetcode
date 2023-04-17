class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candles, int extraCandies) {
        vector<bool> ans(candles.size());
        int mx=*max_element(candles.begin(),candles.end());
        for(int i=0;i<candles.size();i++)
            if(candles[i]+extraCandies>=mx)
                ans[i]=1;
        return ans;
    }
};
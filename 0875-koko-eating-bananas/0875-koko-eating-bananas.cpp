class Solution {
public:
    bool condition(int k, vector<int> &piles, int &h){
        int sum=0;
        for(auto &p:piles)
            sum+=(p+k-1)/k;
        return sum<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=0,mn=1;
        for(auto &p:piles)
            mx=max(mx,p);
        while(mn<mx){
            int mid=mn+(mx-mn)/2;
            (condition(mid,piles,h)?mx=mid:mn=mid+1); 
        }
        return mn;
    }
};
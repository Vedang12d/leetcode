class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        while(n){
            int t=n/5;
            ans+=t;
            n=t;
        }
        return ans;
    }
};
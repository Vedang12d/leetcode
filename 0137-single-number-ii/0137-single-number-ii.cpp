class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,twos=0;
        for(auto &x:nums){
            twos|=ones&x;
            ones^=x;
            int temp=~(ones&twos);
            ones&=temp;
            twos&=temp;
        }
        return ones;
    }
};
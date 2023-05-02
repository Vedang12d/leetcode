class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ct=0;
        for(auto &num:nums){
            if(!num)
                return 0;
            if(num<0)
                ct++;                
        }
        if(ct&1)
            return -1;
        return 1;
    }
};
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq,need;
        for(auto num:nums)
            freq[num]++;
        for(auto num:nums){
            if(!freq.count(num))
                continue;
            else if(need.count(num)){
                if(!--need[num])
                    need.erase(num);
                need[num+1]++;
            }
            else if(freq.count(num+1)&&freq.count(num+2)){
                if(!--freq[num+1])
                    freq.erase(num+1);
                if(!--freq[num+2])
                    freq.erase(num+2);
                need[num+3]++;
            }
            else
                return 0;
            if(!--freq[num])
                freq.erase(num);
        }
        return 1;
    }
};
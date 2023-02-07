class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0,j=0;j<fruits.size();j++){
            mp[fruits[j]]++;
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(!mp[fruits[i]])
                    mp.erase(fruits[i]);
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
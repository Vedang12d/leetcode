class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        combination(ans,comb,k,1,n);
        return ans;
    }
    void combination(vector<vector<int>> &ans,vector<int> &comb,int &k,int st,int n){
        if(comb.size()==k){
            if(!n)
                ans.push_back(comb);
            return;
        }
        for(int i=st;i<10;i++){
            comb.push_back(i);
            combination(ans,comb,k,i+1,n-i);
            comb.pop_back();
        }
    }
};
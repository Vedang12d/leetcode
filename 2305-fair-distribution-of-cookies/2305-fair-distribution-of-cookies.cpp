class Solution {
public:
    int ans=INT_MAX,k;
    void bt(int i,vector<int>  &cookies,vector<int> &bags){
        if(i==cookies.size()){
            int mx=INT_MIN;
            for(int j=0;j<k;j++)
                mx=max(mx,bags[j]);
            ans=min(ans,mx);
            return;
        }
        for(int j=0;j<k;j++){
            bags[j]+=cookies[i];
            bt(i+1,cookies,bags);
            bags[j]-=cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> bags(k);
        this->k=k;
        bt(0,cookies,bags);
        return ans;
    }
};
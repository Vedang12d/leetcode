class Solution {
public:
    int maxScore=0;
    void backtrack(int i,int rem,int score,vector<int> &ans,vector<int> &v,vector<int>& aa){
        if(i==12){
            if(score>maxScore)
                maxScore=score, ans=v;
            return;
        }
        backtrack(i+1,rem,score,ans,v,aa);
        int need=aa[i]+1;
        if(rem>=need){
            int old=v[i];
            v[i]=need;
            backtrack(i+1,rem-need,score+i,ans,v,aa);
            v[i]=old;
        }
    }
    vector<int> maximumBobPoints(int num, vector<int>& aa) {
        vector<int> ans(12),v(12);
        backtrack(0,num,0,ans,v,aa);
        ans[0]+=num-accumulate(ans.begin(),ans.end(),0);
        return ans;
    }
};
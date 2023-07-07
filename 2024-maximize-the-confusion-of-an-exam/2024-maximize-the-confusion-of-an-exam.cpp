class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            if(!i)
                a[i]=(answerKey[i]=='T');
            else
                a[i]=a[i-1]+(answerKey[i]=='T');
            b[i]=i+1-a[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(answerKey[i]=='T'){
                int at=lower_bound(a.begin(),a.end(),a[i]+k)-a.begin();
                int bt=upper_bound(b.begin(),b.end(),b[i]+k)-b.begin();
                ans=max(ans,max(at-i,bt-i));
            }else{
                int at=upper_bound(a.begin(),a.end(),a[i]+k)-a.begin();
                int bt=lower_bound(b.begin(),b.end(),b[i]+k)-b.begin();
                ans=max(ans,max(at-i,bt-i));
            }
        }
        return ans;
    }
};
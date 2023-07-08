class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        long long a=0,b=0;
        int n=w.size();
        if(k==1||k==n)
            return 0;
        k--;
        vector<long long>x,y;
        for(int i=0;i<n-1;i++)
            x.push_back(w[i]+w[i+1]);
        y=x;
        sort(x.rbegin(),x.rend());
        sort(y.begin(),y.end());
        for(int i=0;i<k;i++)
            a+=x[i], b+=y[i];
        return a-b;
    }
};
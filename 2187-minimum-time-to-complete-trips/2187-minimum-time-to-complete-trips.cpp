class Solution {
public:
    bool check(long long x,vector<int>& time, int &k){
        long long sum=0;
        for(auto &t:time)
            sum+=x/t;
        return sum>=k;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low=1,high=LLONG_MAX;
        for(auto &t:time)
            high=min(high,1LL*t);
        high*=totalTrips;
        while(low<high){
            long long mid=low+(high-low)/2;
            (check(mid,time,totalTrips)?high=mid:low=mid+1);
        }
        return low;
    }
};
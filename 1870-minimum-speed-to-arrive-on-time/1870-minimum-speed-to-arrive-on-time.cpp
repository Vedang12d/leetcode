class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1,high=1e7+1,n=dist.size();
        while(low<high){
            int mid=(low+high)/2;
            double temp=0;
            for(int i=0;i<n-1;i++)
                temp+=(dist[i]+mid-1)/mid;
            temp+=(1.0*dist.back())/mid;
            if(temp<=hour)
                high=mid;
            else
                low=mid+1;
        }
        return (low==1e7+1)?-1:low;
    }
};
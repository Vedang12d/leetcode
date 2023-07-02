class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> degree(n);
        int ans=0;
        function<void(int,int)> backtrack = [&](int i,int count) {
            if(i==requests.size()){
                for(auto ct:degree)
                    if(ct)
                        return;
                ans=max(ans,count);
                return;
            }
            degree[requests[i][0]]--;
            degree[requests[i][1]]++;
            backtrack(i+1,count+1);
            degree[requests[i][0]]++;
            degree[requests[i][1]]--;
            backtrack(i+1,count);
        };
        backtrack(0,0);
        return ans;
    }
};
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_set<int> vis;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<arr.size();i++)
            mp[arr[i]].push_back(i);
        queue<int> q;
        q.push(0);
        vis.insert(0);
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto f=q.front();
                q.pop();
                if(f==arr.size()-1)
                    return ans;
                mp[arr[f]].push_back(f-1);
                mp[arr[f]].push_back(f+1);
                for(auto v:mp[arr[f]]){
                    if(v>=0&&v<arr.size()&&!vis.count(v)){
                        vis.insert(v);
                        q.push(v);
                    }
                }
                mp.erase(arr[f]);
            }
            ans++;
        }
        return 0;
    }
};
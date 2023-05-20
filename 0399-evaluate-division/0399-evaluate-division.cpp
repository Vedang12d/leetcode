class Solution {
public:
    double dfs(string u,string v,unordered_set<string> &vis,unordered_map<string,unordered_map<string,double>> &mp){
        if(!mp.count(u))
            return -1;
        if(mp[u].count(v))
            return mp[u][v];
        for(auto &ne:mp[u]){
            if(vis.count(ne.first))
                continue;
            vis.insert(ne.first);
            double pw=dfs(ne.first,v,vis,mp);
            if(pw!=-1)
                return mp[u][v]=ne.second*pw;
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> mp;
        int i=0;
        for(int i=0;i<values.size();i++){
            auto &u=equations[i][0],&v=equations[i][1];
            mp[u][u]=1.0;
            mp[v][v]=1.0;
            mp[u][v]=values[i];
            mp[v][u]=1.0/values[i];
        }
        vector<double> ans;
        unordered_set<string> vis;
        for(auto &q:queries){
            vis={q[0]};
            ans.push_back(dfs(q[0],q[1],vis,mp));
        }
        return ans;
    }
};
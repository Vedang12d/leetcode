class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> vis1(n,-1),vis2(n,-1);
        vis1[node1]=0, vis2[node2]=0;
        queue<int> q,pq;
        q.push(node1);
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            if(edges[p]!=-1 && vis1[edges[p]]==-1){
                q.push(edges[p]);
                vis1[edges[p]]=vis1[p]+1;
            }
        }
        pq.push(node2);
        while(!pq.empty()){
            auto p=pq.front();
            pq.pop();
            if(edges[p]!=-1 && vis2[edges[p]]==-1){
                pq.push(edges[p]);
                vis2[edges[p]]=vis2[p]+1;
            }
        }
        // for(auto x:vis1)
        //     cout<<x<<' ';
        // cout<<'\n';
        // for(auto x:vis2)
        //     cout<<x<<' ';
        // cout<<'\n';
        int mn=INT_MAX,node=-1;
        for(int i=0;i<n;i++){
            if(vis1[i]==-1||vis2[i]==-1)
                continue;
            if(mn>max(vis1[i],vis2[i]))
                node=i, mn=max(vis1[i],vis2[i]);
        }
        return node;
    }
};
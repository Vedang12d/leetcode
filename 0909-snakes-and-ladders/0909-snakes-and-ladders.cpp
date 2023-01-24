class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> nboard(n*n+1),vis(n*n+1,0);
        int k=1,flag=1;
        for(int i=n-1;i>=0;i--){
            if(flag){
                for(int j=0;j<n;j++,k++)
                    nboard[k]=board[i][j];
            }else{
                for(int j=n-1;j>=0;j--,k++)
                    nboard[k]=board[i][j];
            }
            flag=1-flag;
        }
        queue<int> q;
        q.push(1);
        int ans=0;
        vis[1]=1;
        while(!q.empty()){
            ans++;
            int m=q.size();
            while(m--){
                int cur=q.front();
                q.pop();
                for(int j=1;j<7;j++){
                    int next=cur+j;
                    if(nboard[next]!=-1)
                        next=nboard[next];
                    if(vis[next])
                        continue;
                    if(next==n*n)
                        return ans;
                    vis[next]=1;
                    q.push(next);
                }
            }
        }
        return -1;
    }
};
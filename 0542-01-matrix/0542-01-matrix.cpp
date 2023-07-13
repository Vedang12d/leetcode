class Solution {


public:

void bfs(vector<vector<int>>&mat)
{
    vector<pair<int,int>>temp={{-1,0},{0,-1},{1,0},{0,1}};
    queue<pair<pair<int,int>,int>>q;
    vector<vector<int>>vis(mat.size(),vector<int>(mat[0].size(),0));
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
                 if(mat[i][j]==0)
                 {
                     q.push({{i,j},0});
                 }
        }
    }



    while(!q.empty())
    {
        auto i=q.front();
            
            if(i.first.first==4 and i.first.second==3)
            {
                cout<<i.second<<""<<endl;
            }
    q.pop();
        for(auto node:temp)
        {
            int x=i.first.first+node.first;
            int y=i.first.second+node.second;
            if(x>-1 and x<mat.size() and y>-1 and y<mat[0].size())
            {
                
                if(mat[x][y]==1 and vis[x][y]!=1)
                {
                  
                    vis[x][y]=1;
                    mat[x][y]=i.second+1;
   
                    q.push({{x,y},i.second+1});
                }
                else if(mat[x][y]!=0 and vis[x][y]==1){
                   
                   if(mat[x][y]>(i.second+1) )
                   {
                    
                 mat[x][y]=i.second+1;
                       
                   }
                }
            }
        }
        

    }
}
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        bfs(mat);
        return mat;
    }
};
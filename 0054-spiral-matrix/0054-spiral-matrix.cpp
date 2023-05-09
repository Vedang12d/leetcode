#define pb push_back
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int rowst=0,rowen=n-1,colst=0,colen=m-1;
        vector<int> res;
        while(rowst<=rowen&&colst<=colen){
            for(int i=colst;i<=colen;i++)
                res.pb(mat[rowst][i]);
            rowst++;
            for(int i=rowst;i<=rowen;i++)
                res.pb(mat[i][colen]);
            colen--;
            if(rowst<=rowen){
                for(int i=colen;i>=colst;i--)
                    res.pb(mat[rowen][i]);
            }
            rowen--;
            if(colst<=colen){
                for(int i=rowen;i>=rowst;i--)
                    res.pb(mat[i][colst]);
            }
            colst++;
        }
        return res;
    }
};
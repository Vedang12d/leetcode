class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int ans=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] and i and j)
                    mat[i][j]=min({mat[i-1][j],mat[i][j-1],mat[i-1][j-1]})+1;
                ans+=mat[i][j];
            }
        }
        return ans;
    }
};
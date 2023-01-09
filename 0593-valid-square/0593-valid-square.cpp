class Solution {
public:
    int distance(vector<int> &p1,vector<int> &p2){
        return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> pts={p1,p2,p3,p4};
        unordered_set<int> st;
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                int dist=distance(pts[i],pts[j]);
                if(!dist)
                    return 0;
                else
                    st.insert(dist);
            }
        }
        return st.size()==2;
    }
};
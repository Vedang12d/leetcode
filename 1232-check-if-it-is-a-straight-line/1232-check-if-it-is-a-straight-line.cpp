class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        unordered_set<double> st;
        for(int i=1;i<coordinates.size();i++){
            if(coordinates[i][0]==coordinates[0][0])
                st.insert(INT_MAX);
            else
                st.insert((0.0+coordinates[i][1]-coordinates[0][1])/(coordinates[i][0]-coordinates[0][0]));
        }
        // for(auto i:st)
        //     cout<<i<<' ';
        // cout<<'\n';
        return st.size()==1;
    }
};
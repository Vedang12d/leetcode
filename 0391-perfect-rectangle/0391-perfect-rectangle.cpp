class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int,int>> st;
        int x1=INT_MAX,x2=INT_MIN,y1=INT_MAX,y2=INT_MIN;
        long long area=0;
        for(auto rect:rectangles){
            x1=min(rect[0],x1);
            y1=min(rect[1],y1);
            x2=max(rect[2],x2);
            y2=max(rect[3],y2);
            area+=(1LL*(rect[2]-rect[0]))*(1LL*(rect[3]-rect[1]));
            if(st.count({rect[0],rect[1]}))
                st.erase({rect[0],rect[1]});
            else
                st.insert({rect[0],rect[1]});
            if(st.count({rect[0],rect[3]}))
                st.erase({rect[0],rect[3]});
            else
                st.insert({rect[0],rect[3]});
            if(st.count({rect[2],rect[3]}))
                st.erase({rect[2],rect[3]});
            else
                st.insert({rect[2],rect[3]});
            if(st.count({rect[2],rect[1]}))
                st.erase({rect[2],rect[1]});
            else
                st.insert({rect[2],rect[1]});
        }
        if(st.size()!=4||!st.count({x1,y1})||!st.count({x1,y2})||!st.count({x2,y1})||!st.count({x2,y2}))
            return 0;
        return area==(1LL*(x2-x1))*(1LL*(y2-y1));
    }
};
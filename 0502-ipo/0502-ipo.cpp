class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<vector<int>> pro;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> cap;
        for(int i=0;i<profits.size();i++)
            cap.push({capital[i],profits[i]});
        for(int i=0;i<k;i++){
            while(!cap.empty()&&cap.top()[0]<=w){
                auto p=cap.top();
                swap(p[0],p[1]);
                cap.pop();
                pro.push(p);
            }
            if(pro.empty())
                break;
            w+=pro.top()[0];
            pro.pop();
        }
        return w;
    }
};
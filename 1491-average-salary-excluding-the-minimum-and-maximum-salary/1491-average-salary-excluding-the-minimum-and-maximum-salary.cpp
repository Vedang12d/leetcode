class Solution {
public:
    double average(vector<int>& salary) {
        int mni=min_element(salary.begin(),salary.end())-salary.begin(),mxi=max_element(salary.begin(),salary.end())-salary.begin();
        double ans=0;
        for(int i=0;i<salary.size();i++){
            if(i==mni||i==mxi)
                continue;
            ans+=salary[i];
        }
        return ans/(salary.size()-2);
    }
};
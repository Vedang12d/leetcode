class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0,y=0;
        vector<int> sec(10,0),gue(10,0);
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])
                x++;
            else{
                sec[secret[i]-'0']++;
                gue[guess[i]-'0']++;
            }
        }
        for(int i=0;i<sec.size();i++)
            y+=min(sec[i],gue[i]);
        return to_string(x)+"A"+to_string(y)+"B";
    }
};
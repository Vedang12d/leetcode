class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a||b||c){
            int x=a&1,y=b&1,z=c&1;
            ans+=(z?(!x and !y):x+y);
            a>>=1, b>>=1, c>>=1;
        }
        return ans;
    }
};
class Solution {
public:
    double myPow(double x, int n) {
        if(!n)
            return 1.0;
        if(n&1)
            return (n<0)?1.0/(x*myPow(x,abs(n)-1)):x*myPow(x,abs(n)-1);
        double a=myPow(x,abs(n/2));
        return (n<0)?1.0/(a*a):a*a;
    }
};
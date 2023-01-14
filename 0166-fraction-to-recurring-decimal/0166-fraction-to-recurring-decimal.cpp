class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if(!num)
            return "0";
        string s;
        if(num>0 ^ den>0)
            s+='-';
        long long n=abs(num),d=abs(den),r=n%d;
        s+=to_string(n/d);
        if(!r)
            return s;
        s+='.';
        unordered_map<long long,int> mp;
        while(r){
            if(mp.count(r)){
                s.insert(mp[r],"(");
                s+=')';
                break;
            }
            mp[r]=s.size();
            r*=10;
            s+=to_string(r/d);
            r%=d;
        }
        return s;
    }
};
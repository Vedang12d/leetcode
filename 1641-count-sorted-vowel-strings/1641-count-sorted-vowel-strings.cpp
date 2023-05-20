class Solution {
public:
    string vowels="aeiou";
    int rec(int i,int &n,string &s){
        if(i==5||s.size()==n)
            return s.size()==n;
        s.push_back(vowels[i]);
        int pick=rec(i,n,s);
        s.pop_back();
        int notpick=rec(i+1,n,s);
        return pick+notpick;
    }
    int countVowelStrings(int n) {
        string s;
        return rec(0,n,s);
    }
};
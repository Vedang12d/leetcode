class Solution {
public:
    bool vowel(char &ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    int maxVowels(string s, int k) {
        int n=s.size(),ct=0,ans=0;
        for(int i=0;i<n;i++){
            ct+=vowel(s[i])-(i<k?0:vowel(s[i-k]));
            ans=max(ans,ct);
        }
        return ans;
    }
};
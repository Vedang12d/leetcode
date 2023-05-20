class Solution {
public:
    int countVowelStrings(int n) {
        int ans=1;
        for(int i=n+1;i<n+5;i++)
            ans*=i;
        return ans/24;
    }
};
class Solution {
public:
    bool detectCapitalUse(string word) {
        return all_of(word.begin(),word.end(),[](char ch){return isupper(ch);})||all_of(word.begin()+1,word.end(),[](char ch){return islower(ch);});
    }
};
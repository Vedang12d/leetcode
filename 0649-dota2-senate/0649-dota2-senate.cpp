class Solution {
public:
    string predictPartyVictory(string senate) {
        int len=senate.size()+1,bal=0;
        while(senate.size()<len){
            len=senate.size();
            string s;
            for(auto &ch:senate){
                if(ch=='R'){
                    if(bal>=0)
                        s+=ch;
                    bal++;
                }else{
                    if(bal<=0)
                        s+=ch;
                    bal--;
                }
            }
            senate=s;
        }
        return senate[0]=='R'?"Radiant":"Dire";
    }
};
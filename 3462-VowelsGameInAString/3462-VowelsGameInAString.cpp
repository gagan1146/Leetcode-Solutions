// Last updated: 19/12/2025, 19:23:55
class Solution {
public:
    bool doesAliceWin(string s) {
        string x ="aeiouAEIOU";
        for(auto it:s){
            for(auto p:x){
                if(p==it) return true;
            }
        }
        return false;
    }
};
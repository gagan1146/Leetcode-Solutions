// Last updated: 19/12/2025, 19:23:11
class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        n-=10;
        int k=9;
        bool c=true;
        while(true){
            if(n<k){
                if(c) return true;
                return false;
            }
            n=n-k;
            k--;
            c=!c;
        }
        return true;
    }
};
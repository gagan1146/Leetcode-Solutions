// Last updated: 21/12/2025, 07:25:17
class Solution {
public:
    long long lastInteger(long long n) {
        long long h = 1, s = 1, r = 0;
        while(n>1){
            if(r==1&&n%2==0) h+=s;
            n=(n+1)/2;
            s*=2;
            r^=1;
        }
        return h;
    }
};
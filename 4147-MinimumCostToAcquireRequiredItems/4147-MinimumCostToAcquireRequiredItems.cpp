// Last updated: 29/12/2025, 21:48:24
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long a = need1, b = need2, r = 0;
        if(a==0&&b==0) return 0;
        if(costBoth<(cost1+cost2)){
            long long t = min(a,b);
            r += (t*costBoth);
            a-=t;b-=t;
        }
        if(a>0)r+=a*min((long long)cost1,(long long)costBoth);
        if(b>0)r+=b*min((long long)cost2,(long long)costBoth);
        return r;
    }
};
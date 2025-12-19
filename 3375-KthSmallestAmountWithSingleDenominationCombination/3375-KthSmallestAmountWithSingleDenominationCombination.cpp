// Last updated: 19/12/2025, 19:24:15
#define ll long long

class Solution {
public:
    ll countLessThanOrEqualToX(vector<int>& coins,ll midX){
        int m = coins.size();
        int allOnes = (1<<m)-1;
        ll count = 0;
        for(int mask=1;mask<=allOnes;mask++){
            ll lcmOfSetBits=1;
            for(int j=0;j<m;j++){
                if(mask & (1<<j)){
                    lcmOfSetBits = lcm(lcmOfSetBits,coins[j]);
                }
            }
            if(__builtin_popcount(mask) & 1){
                count+=(midX/lcmOfSetBits);
            }
            else{
                count-=(midX/lcmOfSetBits);
            }
        }
        return count; 
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ll l=1;
        ll r = 1e11;
        ll ans= 0;
        while(l<=r){
            ll midX = (l+r)/2;
            ll count = countLessThanOrEqualToX(coins,midX);
            if(count<k){
                l=midX+1;
            }
            else{
                ans=midX;
                r=midX-1;
            }
        }
        return ans;
    }
};
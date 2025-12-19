// Last updated: 19/12/2025, 19:20:20
class Solution {
public:
    int MOD = 1000000007;
    int countCoprime(vector<vector<int>>& mat) {
        unordered_map<int,long long>dp;
        dp[0]=1;
        for(auto &x:mat){
            unordered_map<int,long long>dp1;
            for(auto &y:x){
                for(auto &[a,b]:dp){
                    int val = a ? __gcd(a,y):y;
                    dp1[val]=(dp1[val]+b)%MOD;
                }
            }
            dp=move(dp1);
        }
        return dp[1]%MOD;
    }
};
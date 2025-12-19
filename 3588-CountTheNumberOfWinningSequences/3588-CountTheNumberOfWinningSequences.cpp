// Last updated: 19/12/2025, 19:23:29
class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[3][1001][2001]; 

    long long f(string &s, int prev, int ind, int sumi) {
        if (ind >= s.size()) {
            return sumi > 0 ? 1 : 0;
        }

        if (dp[prev][ind][sumi + 1000] != -1)
            return dp[prev][ind][sumi + 1000];

        long long takeF = 0, takeW = 0, takeE = 0;

        if (s[ind] == 'F') {
            if (prev != 0) takeF = f(s, 0, ind + 1, sumi) % MOD;
            if (prev != 1) takeW = f(s, 1, ind + 1, sumi + 1) % MOD;
            if (prev != 2) takeE = f(s, 2, ind + 1, sumi - 1) % MOD;
        } 
        else if (s[ind] == 'W') {
            if (prev != 0) takeF = f(s, 0, ind + 1, sumi - 1) % MOD;
            if (prev != 1) takeW = f(s, 1, ind + 1, sumi) % MOD;
            if (prev != 2) takeE = f(s, 2, ind + 1, sumi + 1) % MOD;
        } 
        else { // 'E'
            if (prev != 0) takeF = f(s, 0, ind + 1, sumi + 1) % MOD;
            if (prev != 1) takeW = f(s, 1, ind + 1, sumi - 1) % MOD;
            if (prev != 2) takeE = f(s, 2, ind + 1, sumi) % MOD;
        }

        return dp[prev][ind][sumi + 1000] = (takeF + takeW + takeE) % MOD;
    }

    int countWinningSequences(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        long long ans = (f(s, 0, 0, 0) + f(s, 1, 0, 0) + f(s, 2, 0, 0)) % MOD;
        return (ans * 1LL * ((MOD + 1) / 2)) % MOD; 
    }
};

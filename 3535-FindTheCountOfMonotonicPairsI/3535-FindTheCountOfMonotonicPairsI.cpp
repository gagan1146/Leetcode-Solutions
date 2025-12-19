// Last updated: 19/12/2025, 19:23:43
#define ll long long
class Solution {
    const int MOD = 1e9 + 7;

public:
    int countOfPairs(vector<int>& nums) {
        
        int n = nums.size();
        ll ans = 0;

        int dp[n][1001];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= nums[0]; i++) {
            dp[0][i] = 1;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int prev1 = 0; prev1 <= nums[ind - 1]; prev1++) {
                for (int i = prev1; i <= nums[ind]; i++) {
                    int y = nums[ind] - i;

                    if (y <= nums[ind - 1] - prev1)
                        dp[ind][i] = (dp[ind][i] + dp[ind - 1][prev1]) % MOD;
                }
            }
        }

        for (int i = 0; i <= nums[n - 1]; i++) {
            ans = (ans + dp[n - 1][i]) % MOD;
        }

        return ans;
    }
};
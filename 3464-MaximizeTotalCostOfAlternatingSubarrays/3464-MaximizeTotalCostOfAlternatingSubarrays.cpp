// Last updated: 23/12/2025, 21:47:27
class Solution {
public:
    long long dp[100005][2];
    long long f(int i, int p, vector<int>& nums) {
        if (i == nums.size()) return 0;
        if (dp[i][p] != -1) return dp[i][p];
        long long sign = (p == 0 ? 1LL : -1LL);
        long long take =
            sign * nums[i] +
            f(i + 1, p ^ 1, nums);
        long long notTake =
            nums[i] +
            f(i + 1, 1, nums);
        return dp[i][p] = max(take, notTake);
    }

    long long maximumTotalCost(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, nums);
    }
};
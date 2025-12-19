// Last updated: 19/12/2025, 19:21:46
class Solution {
public:
    int MOD = 1000000007;
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<long long> dp(n + 1, 0);
        vector<long long> ps(n + 1, 0);
        dp[0] = 1;
        ps[0] = 1;

        deque<int> md, mxd;
        int lt = 0;

        for (int rt = 0; rt < n; ++rt) {
            while (!md.empty() && nums[rt] < nums[md.back()])
                md.pop_back();
            md.push_back(rt);

            while (!mxd.empty() && nums[rt] > nums[mxd.back()])
                mxd.pop_back();
            mxd.push_back(rt);

            while (nums[mxd.front()] - nums[md.front()] > k) {
                ++lt;
                while (!mxd.empty() && mxd.front() < lt)
                    mxd.pop_front();
                while (!md.empty() && md.front() < lt)
                    md.pop_front();
            }

            if (lt == 0)
                dp[rt + 1] = ps[rt] % MOD;
            else
                dp[rt + 1] =
                    (ps[rt] - ps[lt - 1] + MOD) % MOD;

            ps[rt + 1] = (ps[rt] + dp[rt + 1]) % MOD;
        }

        return dp[n] % MOD;
    }
};
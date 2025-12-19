// Last updated: 19/12/2025, 19:21:29
class Solution {
public:
    int MOD = 1000000007;

    int countTrapezoids(vector<vector<int>>& points) {
        long count = 0;
        int n = points.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[points[i][1]]++;
        }
        vector<long long> vals;
        for (auto it : mp) {
            if (it.second >= 2) {
                long long c = 1LL * it.second * (it.second - 1) / 2;
                vals.push_back(c % MOD);
            }
        }
        long long sum = 0, sqsum = 0;
        for (auto v : vals) {
            sum = (sum + v) % MOD;
            sqsum = (sqsum + (v * v) % MOD) % MOD;
        }
        long long x = (sum * sum % MOD - sqsum + MOD) % MOD;
        x = (x * ((MOD + 1) / 2)) % MOD;

        return (int)x;
    }
};
// Last updated: 19/12/2025, 19:20:30
class Solution {
public:
    long long countDistinct(long long n) {
        string digits = to_string(n);
        int m = digits.size();

        vector<long long> power9(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            power9[i] = power9[i - 1] * 9LL;
        }

        long long total = 0;

        for (int length = 1; length < m; length++) {
            total += power9[length];
        }

        for (int idx = 0; idx < m; idx++) {
            int d = digits[idx] - '0';
            if (d == 0) {
                return total;
            }
            total += (long long)(d - 1) * power9[m - idx - 1];
        }

        return total + 1;
    }
};
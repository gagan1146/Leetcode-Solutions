// Last updated: 19/12/2025, 19:20:10
vector<bool> spf;
vector<int> vals;
const int MAXI = 5e5 + 1;
auto init = []() {
    spf.resize(MAXI, true);
    spf[0] = spf[1] = false;
    for (int i = 2; i * i <= MAXI; i++) {
        if (spf[i]) {
            for (int p = i + i; p <= MAXI; p += i) {
                if (spf[p]) {
                    spf[p] = false;
                }
            }
        }
    }

    auto isPrime = [](int n) {
        if (n < 2) return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }

        return true;
    };

    long long sum = 0;
    for (int i = 2; i < MAXI; i++) {
        if (spf[i]) {
            sum += i;
            if (sum < MAXI) {
                if (spf[sum]) vals.push_back(sum);
            } else if (isPrime(sum)) vals.push_back(sum);
        }
    }

    return 0;    
}();
class Solution {
public:
    int largestPrime(int n) {
        if (n == 1) return 0;
        return *prev(upper_bound(vals.begin(), vals.end(), n));
    }
};
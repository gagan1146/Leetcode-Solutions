// Last updated: 19/12/2025, 19:21:36
class Solution {
public:
    int MOD = 1000000007;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        long long ans = 1;

        for (int i = 1; i < n; i++) {
            if (complexity[0] >= complexity[i])
                return 0;

            ans = (ans * i) % MOD;
        }

        return ans;
    }
};
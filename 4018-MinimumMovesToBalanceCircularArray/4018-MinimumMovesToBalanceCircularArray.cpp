// Last updated: 19/12/2025, 19:20:51
class Solution {
public:
    long long minMoves(vector<int>& a) {
        long long n = a.size(), sum = accumulate(a.begin(), a.end(), 0ll), idx = -1;
        if(sum < 0)
            return -1;
        for(int i = 0; i < n; i++) {
            if(a[i] < 0) {
                idx = i;
                break;
            }
        }
        if(idx == -1)
            return 0;
        long long d = 1, l = (idx - 1 + n) % n, r = (idx + 1) % n, ans = 0;
        int goal = abs(a[idx]);
        while(goal > 0) {
            long long take;
            if(a[l] > 0) {
                take = min(goal, a[l]);
                goal -= take;
                ans += take * d;
            }
            if(goal > 0 && a[r] > 0) {
                take = min(goal, a[r]);
                goal -= take;
                ans += take * d;
            }
            l = (l - 1 + n) % n;
            r = (r + 1) % n;
            d++;
        }
        return ans;
    }
};
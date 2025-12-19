// Last updated: 19/12/2025, 19:21:09
class Solution {
public:
    bool check(string& s, int mid, long long k, int n, vector<int>& order) {
        vector<bool> star(n, false);
        for (int i = 0; i <= mid; i++) {
            star[order[i]] = true;
        }
        long long invalid = 0, len = 0;
        for (int i = 0; i < n; i++) {
            if (!star[i]) {
                len++;
            } else {
                invalid += (len * (len + 1)) / 2;
                len = 0;
            }
        }
        if (len > 0) {
            invalid += (len * (len + 1)) / 2;
        }
        long long total = (long long)n * (n + 1) / 2;
        long long valid = total - invalid;
        return valid >= k;
    }
    int minTime(string s, vector<int>& order, int k) {
        int n = order.size();
        int low = 0, high = n-1, ans = -1;
        string x1 = s;
        x1[order[0]] = '*';
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(s, mid, k, n, order)) {
                high = mid - 1;
                ans = mid;
            } else
                low = mid + 1;
        }
        return ans;
    }
};
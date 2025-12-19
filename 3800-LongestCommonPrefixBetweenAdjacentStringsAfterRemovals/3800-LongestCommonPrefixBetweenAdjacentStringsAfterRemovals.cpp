// Last updated: 19/12/2025, 19:22:02
class Solution {
public:
    int f(string &a, string &b) {
        int i = 0, n = min(a.size(), b.size());
        while (i < n && a[i] == b[i]) ++i;
        return i;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        if (n == 1) return {0};
        if(n==2)return {0,0};
        vector<int> qx(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            qx[i] = f(words[i], words[i + 1]);
        }
        vector<int> pf(n - 1), sf(n - 1);
        pf[0] = qx[0];
        for (int i = 1; i < n - 1; ++i) {
            pf[i] = max(pf[i - 1], qx[i]);
        }
        sf[n - 2] = qx[n - 2];
        for (int i = n - 3; i >= 0; --i) {
            sf[i] = max(sf[i + 1], qx[i]);
        }
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            int mx = 0;
            if (i == 0) {
                mx = sf[1];
            } else if (i == n - 1) {
                mx = pf[n - 3];
            } else {
                if (i - 2 >= 0) mx = max(mx, pf[i - 2]);
                if (i + 1 < n - 1) mx = max(mx, sf[i + 1]);
                mx = max(mx, f(words[i - 1], words[i + 1]));
            }
            res[i] = mx;
        }
        return res;
    }
};
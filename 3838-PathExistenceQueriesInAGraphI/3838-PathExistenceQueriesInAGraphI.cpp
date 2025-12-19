// Last updated: 19/12/2025, 19:21:43
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> p(n), sz(n,1);
        for (int i = 0; i < n; i++) p[i] = i;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i+1] - nums[i] <= maxDiff) {
                int a = i, b = i+1;
                while (p[a] != a) { p[a] = p[p[a]]; a = p[a]; }
                while (p[b] != b) { p[b] = p[p[b]]; b = p[b]; }
                if (a != b) {
                    if (sz[a] < sz[b]) swap(a, b);
                    p[b] = a;
                    sz[a] += sz[b];
                }
            }
        }
        vector<bool> ans;
        for (auto& q : queries) {
            int a = q[0], b = q[1];
            while (p[a] != a) { p[a] = p[p[a]]; a = p[a]; }
            while (p[b] != b) { p[b] = p[p[b]]; b = p[b]; }
            ans.push_back(a == b);
        }
        return ans;
    }
};
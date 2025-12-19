// Last updated: 19/12/2025, 19:20:02
class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> right(n);
        right[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= nums[i + 1]) right[i] = right[i + 1];
            else right[i] = i;
        }
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + (long long)(right[i] - i + 1);
        }
        vector<long long> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            int idx = lower_bound(right.begin(), right.end(), r) - right.begin();
            int k = max(l, idx);
            long long part1 = (k > l) ? pre[k] - pre[l] : 0;
            long long part2 = 0;
            if (k <= r) {
                long long len = (long long)r - k + 1;
                part2 = len * (len + 1) / 2;
            }
            ans.push_back(part1 + part2);
        }
        return ans;
    }
};
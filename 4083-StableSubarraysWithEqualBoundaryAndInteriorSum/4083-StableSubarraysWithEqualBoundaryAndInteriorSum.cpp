// Last updated: 19/12/2025, 19:20:13
class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        long long c = 0, p = 0;
        map<pair<long long, long long>, int> mp;
        for (int i = 0; i < n; i++) {
            p += capacity[i];
            if (i >= 2) {
                int j = i - 2;
                mp[{capacity[j], p - capacity[i] - capacity[i - 1]}]++;
            }
            long long v = capacity[i], t = p - 2 * capacity[i];
            if (mp.count({v, t}))
                c += mp[{v, t}];
        }
        return c;
    }
};
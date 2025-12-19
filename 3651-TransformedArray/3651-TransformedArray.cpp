// Last updated: 19/12/2025, 19:22:55
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 0);
        for (int j = 0; j < n; j++) {
            int x = nums[j];
            if (x == 0) v[j] = x;
            else {
                int idx = ((j + x) % n + n) % n;
                v[j] = nums[idx];
            }
        }
        return v;
    }
};
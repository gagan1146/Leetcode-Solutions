// Last updated: 19/12/2025, 19:21:41
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> v1 = nums;
        unordered_map<int, int> mp1;
        int n = nums.size(), c = 0;

        for (int i = 0; i < n; i++) {
            mp1[nums[i]] = i;
        }

        sort(v1.begin(), v1.end());

        map<int, vector<int>> mp;
        for (int i : v1) {
            int x = 0, y = i;
            while (y > 0) {
                x += y % 10;
                y = y / 10;
            }
            mp[x].push_back(i);
        }

        vector<int> ans;
        for (auto key : mp) {
            for (int i = 0; i < key.second.size(); i++) {
                ans.push_back(key.second[i]);
            }
        }

        vector<int> curr = nums;
        unordered_map<int, int> ind;
        for (int i = 0; i < n; i++) {
            ind[curr[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            if (curr[i] != ans[i]) {
                c++;
                int idx = ind[ans[i]];
                ind[curr[i]] = idx;
                ind[ans[i]] = i;
                swap(curr[i], curr[idx]);
            }
        }

        return c;
    }
};

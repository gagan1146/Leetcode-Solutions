// Last updated: 19/12/2025, 19:19:48
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if(k == 0) return nums.size();
        sort(nums.begin(), nums.end());
        int i = nums.size() - k, n = nums[i];
        if(nums[0] == n) return 0;
        while(n == nums[i]) i--;
        return i + 1;
    }
};
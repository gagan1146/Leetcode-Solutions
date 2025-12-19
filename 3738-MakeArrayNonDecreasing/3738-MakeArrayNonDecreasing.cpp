// Last updated: 19/12/2025, 19:22:31
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size(), c = 0, maxi = nums[0];
        for (int j = 1; j < n; j++) {
            if (nums[j] < maxi) {
                c++;
                maxi = max(maxi,nums[j]);
            }
            maxi=max(maxi, nums[j]) ;
        }
        return n-c;
    }
};
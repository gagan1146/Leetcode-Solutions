// Last updated: 19/12/2025, 19:21:03
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = 0, maxi = 1;

        while (j < n) {
            long long val = 1LL * nums[i] * k;  
            long long limit = min(val, 1000000000LL); 

            if (nums[j] <= limit) {
                maxi = max(maxi, j - i + 1);
                j++;                         
            } else {
                i++;                         
            }
        }
        return n - maxi;
    }
};
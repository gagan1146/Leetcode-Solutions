// Last updated: 19/12/2025, 19:20:56
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = 0LL + *max_element(nums.begin(),nums.end());
        long long mini = 0LL + *min_element(nums.begin(),nums.end());
        long long ans = (maxi-mini)*(0LL+k);
        return ans;
    }
};
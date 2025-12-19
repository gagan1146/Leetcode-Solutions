// Last updated: 19/12/2025, 19:19:47
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(k==n) return 0;
        for(int i=1;i<n;i++) nums[i]+=nums[i-1];
        return nums[n-1] - nums[n-k-1] - nums[k-1];
    }
};
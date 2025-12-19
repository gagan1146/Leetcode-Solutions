// Last updated: 19/12/2025, 19:20:15
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) nums[i]=nums[i]*nums[i];
        sort(nums.rbegin(),nums.rend());
        long long res = 0;
        int x = ceil(n/2.0);
        for(int i=0;i<x;i++) res+=nums[i];
        for(int i=x;i<n;i++) res-=nums[i];
        return res;
    }
};
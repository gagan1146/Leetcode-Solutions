// Last updated: 19/12/2025, 19:20:39
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long n = nums1.size(), m = nums2.size(), last=nums2.back(),ans = 0;
        for(int i=0;i<n;i++) ans+=abs(nums1[i]-nums2[i]);
        long long res = INT_MAX;
        for(int i=0;i<n;i++){
            long long x = min(nums1[i],nums2[i]), y = max(nums1[i],nums2[i]);
            long long a = last<x?x-last:(last>y?last-y:0);
            res = min(res,a);
        }
        return ans+1+res;
    }
};
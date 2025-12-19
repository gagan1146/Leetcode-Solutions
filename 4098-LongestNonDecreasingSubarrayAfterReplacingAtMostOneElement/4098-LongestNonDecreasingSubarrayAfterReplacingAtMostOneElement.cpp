// Last updated: 19/12/2025, 19:20:06
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;
        vector<int>l(n,1),r(n,1);
        for(int i=1;i<n;i++) if(nums[i-1]<=nums[i]) l[i]=l[i-1]+1;
        for(int i=n-2;i>=0;i--) if(nums[i]<=nums[i+1]) r[i]=r[i+1]+1;
        int ans = 1;
        for(int i=0;i<n;i++) ans = max(ans,l[i]);
        for(int i=0;i<n-1;i++){
            ans = max(ans,l[i]+1);
            ans = max(ans,r[i+1]+1);
            bool x = (i==0) || (nums[i-1]<=nums[i+1]);
            bool y = (i+2>=n)||(nums[i]<=nums[i+2]);
            if(x||y) ans = max(ans,l[i]+r[i+1]);
        }
        return min(ans,n);
    }
};
// Last updated: 19/12/2025, 19:20:57
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 2, cur=2;
        for(int i=0;i<n;i++){
            for(int j=i+2;j<n;j++){
                if(nums[j]==(nums[j-1]+nums[j-2])) ans = max(ans,j-i+1);
                else break;
            }
        }
        return ans;
    }
};
// Last updated: 19/12/2025, 19:23:15
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), ans = 0, last = INT_MIN, mn, mx;
        for(int i=0;i<n;i++){
            mn = nums[i] - k;
            mx = nums[i] + k;
            if(last<mn){
                last = mn;
                ans++;
            }
            else if(last<mx){
                last = last + 1;
                ans++;
            }
        }
        return ans;
    }
};
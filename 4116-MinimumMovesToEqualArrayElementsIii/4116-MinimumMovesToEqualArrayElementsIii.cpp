// Last updated: 19/12/2025, 19:19:57
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int ans = 0;
        for(auto it:nums){
            ans += (abs(it-maxi));
        }
        return ans;
    }
};
// Last updated: 19/12/2025, 19:23:54
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(auto it: nums){
            if(it%3!=0) ans += 1;
        }
        return ans;
    }
};
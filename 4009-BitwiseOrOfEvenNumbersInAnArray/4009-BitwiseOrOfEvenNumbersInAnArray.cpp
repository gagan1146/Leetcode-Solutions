// Last updated: 19/12/2025, 19:20:54
class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;
        for(auto it:nums) if(it%2==0) ans = ans | it;
        return ans;
    }
};
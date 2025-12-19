// Last updated: 19/12/2025, 19:20:25
class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int s = 0;
        for(int i=0;i<nums.size();i++){
            if(i%2!=0) s-=nums[i];
            else s+=nums[i];
        }
        return s;
    }
};
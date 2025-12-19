// Last updated: 19/12/2025, 19:22:43
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size()-2;i++){
            if((2*(nums[i]+nums[i+2]))==nums[i+1]){
                c+=1;
            }
        }
        return c;
    }
};
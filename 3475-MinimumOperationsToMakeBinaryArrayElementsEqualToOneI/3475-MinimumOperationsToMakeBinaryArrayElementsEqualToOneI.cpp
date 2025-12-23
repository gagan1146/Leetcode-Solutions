// Last updated: 23/12/2025, 21:47:26
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c = 0, n = nums.size();
        for(int i=0;i<n-2;i++){
            if(nums[i]==0){
                for(int j=i;j<i+3;j++){
                    nums[j] = (nums[j]==1)?0:1;
                }
                c++;
            }
        }
        if(nums[n-1]==0 || nums[n-2]==0) return -1;
        return c;
    }
};
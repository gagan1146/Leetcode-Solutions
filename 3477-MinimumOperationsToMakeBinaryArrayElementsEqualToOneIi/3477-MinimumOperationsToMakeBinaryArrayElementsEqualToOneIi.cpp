// Last updated: 23/12/2025, 21:47:24
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c = 0, n = nums.size();
        for(int i=0;i<n;i++){
            if((nums[i]+c)%2==0){
                c++;
            }
        }
        return c;
    }
};
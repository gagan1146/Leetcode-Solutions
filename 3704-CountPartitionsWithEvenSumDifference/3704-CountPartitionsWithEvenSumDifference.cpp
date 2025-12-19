// Last updated: 19/12/2025, 19:22:40
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), c = 0,sumi;
        for(int j=1;j<n;j++){
            nums[j]+=nums[j-1];
        }
        if(n==1) return 0;
        sumi = nums[n-1];
        for(int j=0;j<n-1;j++){
            int x = 2*nums[j] - sumi;
            if(abs(x)%2==0) c++;
        }
        return c;
    }
};
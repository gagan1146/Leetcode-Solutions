// Last updated: 19/12/2025, 19:21:05
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n<=3) return false;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n-1;j++){
                bool a=true,b=true,c=true;
                for(int k=1;k<=i;k++){
                    if(nums[k]<=nums[k-1]){
                        a=false;
                        break;
                    }
                }
                for(int k=i+1;k<=j;k++){
                    if(nums[k]>=nums[k-1]){
                        b=false;
                        break;
                    }
                }
                for(int k=j+1;k<n;k++){
                    if(nums[k]<=nums[k-1]){
                        c=false;
                        break;
                    }
                }
                if(a & b & c) return true;
            }
        }
        return false;
    }
};
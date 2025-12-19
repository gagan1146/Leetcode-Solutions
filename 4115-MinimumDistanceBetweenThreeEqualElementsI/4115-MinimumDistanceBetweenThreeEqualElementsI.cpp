// Last updated: 19/12/2025, 19:19:59
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = 1e9, n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]==nums[j] && nums[j]==nums[k]){
                        ans = min(ans,(abs(i-j)+abs(j-k)+abs(k-i)));
                    }
                }
            }
        }
        if(ans==1e9) return -1;
        else return ans;
    }
};
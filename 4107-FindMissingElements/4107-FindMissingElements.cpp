// Last updated: 19/12/2025, 19:20:03
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int k = nums[0];
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(k<nums[i]){
                ans.push_back(k);
                i--;
            }
            k++;
        }
        return ans;
    }
};
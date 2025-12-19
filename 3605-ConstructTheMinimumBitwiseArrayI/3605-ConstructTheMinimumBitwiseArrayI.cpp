// Last updated: 19/12/2025, 19:23:24
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size(),flag;
        for(int j=0;j<n;j++){
            if(nums[j]==2) ans.push_back(-1);
            else {
                flag=0;
                for(int i=1;i<2000;i++){
                    if(((i)|(i+1))==nums[j]){
                        ans.push_back(i);
                        flag=1;
                        break;
                    }
                }
                if(flag==0) ans.push_back(-1);
            }
        }
        return ans;
    }
};
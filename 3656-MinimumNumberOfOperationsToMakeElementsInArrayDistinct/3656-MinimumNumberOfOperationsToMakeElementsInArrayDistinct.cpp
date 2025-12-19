// Last updated: 19/12/2025, 19:22:53
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=1;
            }
            else{
                float x =(i+1)/3.0;
                return ceil(x);
            }
        }
        return 0;
    }
};
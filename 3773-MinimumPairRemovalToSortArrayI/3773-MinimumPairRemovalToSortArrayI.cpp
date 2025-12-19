// Last updated: 19/12/2025, 19:22:14
class Solution {
public:
    int isSorted(vector<int>nr){
        for(int i=1;i<nr.size();i++){
            if(nr[i]<nr[i-1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while(!isSorted(nums)){
            int mn=INT_MAX,index=-1;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]+nums[i+1]<mn) mn=nums[i]+nums[i+1],index=i;
            }
            vector<int>new1;
            for(int i=0;i<nums.size();i++){
                if(i==index){
                    new1.push_back(nums[i]+nums[i+1]);
                    i++;
                }
                else{
                    new1.push_back(nums[i]);
                }
            }
            nums=new1;
            ans++;
        }
        return ans;
    }
};
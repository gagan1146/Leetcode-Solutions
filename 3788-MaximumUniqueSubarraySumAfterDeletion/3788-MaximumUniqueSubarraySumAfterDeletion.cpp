// Last updated: 19/12/2025, 19:22:10
class Solution {
public:
    int maxSum(vector<int>& nums) {
        map<int,int>mp;
        int s=0;
        for(auto i:nums){
            if(i>0) mp[i]=1;
        }
        if(mp.size()==0){
            s=*max_element(nums.begin(),nums.end());
        }
        for(auto i:mp){
            s+=i.first;
        }
        return s;
    }
};
// Last updated: 19/12/2025, 19:23:13
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(nums[i]<k) return -1;
        }
        if(mp.find(k)!=mp.end()) return mp.size()-1;
        else return mp.size();
    }
};
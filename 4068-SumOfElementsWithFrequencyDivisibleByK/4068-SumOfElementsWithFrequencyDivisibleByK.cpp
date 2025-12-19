// Last updated: 19/12/2025, 19:20:21
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int,int>mp;
        int n = nums.size(), count = 0;
        for(auto it:nums) mp[it]++;
        for(auto it:mp){
            if(it.second%k==0) count += (it.second*it.first);
        }
        return count;
    }
};
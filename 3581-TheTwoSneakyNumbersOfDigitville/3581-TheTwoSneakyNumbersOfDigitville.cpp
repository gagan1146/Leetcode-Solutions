// Last updated: 19/12/2025, 19:23:31
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto it:nums){
            mp[it]++;
            if(mp[it]==2) ans.push_back(it);
        }
        return ans;
    }
};
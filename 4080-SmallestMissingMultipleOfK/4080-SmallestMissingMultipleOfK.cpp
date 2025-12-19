// Last updated: 19/12/2025, 19:20:14
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto it:nums) mp[it]=1;
        for(int i=k;i<10000;i+=k){
            if(mp.find(i)==mp.end()) return i;
        }
        return -1;
    }
};
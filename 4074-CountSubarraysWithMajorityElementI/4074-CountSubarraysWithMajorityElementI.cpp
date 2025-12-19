// Last updated: 19/12/2025, 19:20:17
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count = 0, n = nums.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            for(int j=i;j<n;j++){
                mp[nums[j]]++;
                if(mp.find(target)!=mp.end() && mp[target]>((j-i+1)/2.0)) count++;
            }
        }
        return count;
    }
};
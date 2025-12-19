// Last updated: 19/12/2025, 19:19:56
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>>mp;
        int n = nums.size(),ans = 1e9;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto it:mp){
            if(it.second.size()>2){
                for(int i=2;i<it.second.size();i++){
                    ans = min(ans,(abs(it.second[i]-it.second[i-1])+abs(it.second[i-1]-it.second[i-2])+abs(it.second[i-2]-it.second[i])));
                }
            }
        }
        if(ans==1e9) return -1;
        return ans;
    }
};
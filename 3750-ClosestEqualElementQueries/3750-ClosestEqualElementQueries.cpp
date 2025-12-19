// Last updated: 19/12/2025, 19:22:26
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;
        for(auto i:queries){
            int n = nums[i];
            if(mp[n].size()==1){
                ans.push_back(-1);
                continue;
            }

            int ind = lower_bound(mp[n].begin(),mp[n].end(),i)-mp[n].begin();

            int prev = (ind + mp[n].size() - 1)%mp[n].size();
            int next = (ind+1)%mp[n].size();

            if(prev>ind){
                prev = mp[n][prev]-nums.size();
            } else {
                prev = mp[n][prev];
            }

            if(next<ind){
                next = mp[n][next]+nums.size();
            } else {
                next = mp[n][next];
            }
            
            ans.push_back(min(i-prev, abs(next-i)));
        }
        return ans;
    }
};
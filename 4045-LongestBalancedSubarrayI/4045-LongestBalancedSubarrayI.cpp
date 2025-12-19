// Last updated: 19/12/2025, 19:20:37
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            int odd = 0, even = 0;
            for(int j=i;j<n;j++){
                if(mp.find(nums[j])==mp.end()){
                    mp[nums[j]]=1;
                    if(nums[j]%2==0) even++;
                    else odd++;
                }
                if(odd==even) ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};
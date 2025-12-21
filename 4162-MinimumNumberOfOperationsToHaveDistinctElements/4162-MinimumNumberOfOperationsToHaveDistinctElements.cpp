// Last updated: 21/12/2025, 07:25:14
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(),i=0,r=0;
        unordered_map<int,int>mp;
        int d = 0;
        for(auto x:nums) if(++mp[x]==2)d++;
        if(d==0) return 0;
        while(i<n){
            r++;
            for(int j=0;j<3&&i<n;j++,i++){
                if(--mp[nums[i]]==1)d--;
            }
            if(d==0) break;
        }
        return r;
    }
};
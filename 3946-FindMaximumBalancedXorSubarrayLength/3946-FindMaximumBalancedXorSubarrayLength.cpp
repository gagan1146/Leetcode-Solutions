// Last updated: 19/12/2025, 19:21:08
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size(), x = 0, d = 0, r = 0,val = 100000;
        unordered_map<long long,int>mp;
        long long k = ((long long)x<<32)^(d+val);
        mp[k]=0;
        for(int i=0;i<n;i++){
            x^=nums[i];
            d+=(nums[i]%2==0?1:-1);
            k=((long long)x<<32)^(d+val);
            if(mp.count(k)) r = max(r,i+1-mp[k]);
            else mp[k]=i+1;
        }
        return r;
    }
};
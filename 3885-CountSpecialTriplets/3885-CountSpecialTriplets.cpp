// Last updated: 19/12/2025, 19:21:30
class Solution {
public:
    int MOD=1e9+7;
    int specialTriplets(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        unordered_map<int,int>r,l;
        for(int i:nums) r[i]++;
        for(int i=0;i<n;i++){
            int mid = nums[i];
            r[mid]--;
            int left = l[2*mid];
            int right = r[2*mid];
            ans=(ans+1LL*left*right)%MOD;
            l[mid]++;
        }
        return ans;
    }
};
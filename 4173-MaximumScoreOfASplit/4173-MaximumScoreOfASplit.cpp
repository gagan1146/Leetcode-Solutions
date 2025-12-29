// Last updated: 29/12/2025, 21:48:12
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long>p(n+1,0LL),s(n+1,1000000000);
        for(int i=0;i<n;i++) p[i+1]=p[i]+nums[i];
        for(int i=n-1;i>=0;i--) s[i]=min(s[i+1],(long long)nums[i]);
        long long r = p[n-1]-s[n-1];
        for(int i=n-1;i>0;i--){
            r = max(r,(p[i]-s[i]));
        }
        return r;
    }
};
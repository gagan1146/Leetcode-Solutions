// Last updated: 19/12/2025, 19:20:52
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long>ps(n);
        ps[0]=nums[0];
        for(int i=1;i<n;i++) ps[i] = ps[i-1]+nums[i];
        vector<bool>inc(n),dec(n);
        inc[0]=true;
        for(int i=1;i<n;i++) inc[i]=inc[i-1] && nums[i]>nums[i-1];
        dec[n-1]=true;
        for(int i=n-2;i>=0;i--) dec[i]=dec[i+1] && nums[i]>nums[i+1];
        long long mn = LLONG_MAX;
        for(int i=0;i<n-1;i++){
            if(inc[i] && dec[i+1]) mn = min(mn,abs(ps[i]-(ps[n-1]-ps[i])));
        }
        return mn==LLONG_MAX ? -1:mn;
    }
};
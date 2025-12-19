// Last updated: 19/12/2025, 19:20:16
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>b(n);
        for(int i=0;i<n;i++) b[i]=(nums[i]==target)?1:-1;
        vector<long long>p(n+1,0);
        for(int i=0;i<n;i++) p[i+1]=p[i]+b[i];
        vector<long long>c = p;
        sort(c.begin(),c.end());
        c.erase(unique(c.begin(),c.end()),c.end());
        auto id =[&](long long x) {return int(lower_bound(c.begin(),c.end(),x)-c.begin())+1;};
        struct B{
            int n; vector<long long>f;
            B(int a):n(a),f(a+1,0){}
            void y(int i,long long x){for(;i<=n;i+=i&-i)f[i]+=x;}
            long long s(int i){long long r=0; for(;i>0;i-=i&-i)r+=f[i];return r;}
        } bit((int)c.size());
        long long ans = 0;
        for(int i=0;i<=n;i++){
            int x = id(p[i]);
            ans+=bit.s(x-1);
            bit.y(x,1);
        }
        return ans;
    }
};
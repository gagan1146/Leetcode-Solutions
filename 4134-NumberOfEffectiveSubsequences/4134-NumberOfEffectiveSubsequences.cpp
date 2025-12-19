// Last updated: 19/12/2025, 19:19:53
class Solution {
public:
    int MOD = 1000000007;
    int countEffective(vector<int>& nums) {
        int n = nums.size(), t = 0, k = 0;
        for(int x:nums) t|=x;
        vector<int>b,c(n),pw(n+1);
        for(int i=0;i<21;i++) if(t & (1<<i)){b.push_back(i); k++;}
        int s = 1<<k;
        vector<int>g(s);
        for(int i=0;i<n;i++){
            int x = 0;
            for(int j=0;j<k;j++) if(nums[i] & (1<<b[j])) x|=(1<<j);
            c[i]=x;
        }
        for(int i=0;i<n;i++)g[c[i]]++;
        for(int j=0;j<k;j++){
            for(int m=0;m<s;m++){
                if(m&(1<<j)) g[m]+=g[m^(1<<j)];
            }
        }
        pw[0]=1;
        for(int i=1;i<=n;i++) pw[i]=(pw[i-1]*2)%MOD;
        int f = s-1;
        long long ct=0;
        for(int m=0;m<s;m++){
            int cnt = (int)g[f^m];
            long long v = (pw[cnt]-1+MOD)%MOD;
            if(__builtin_popcount(m)&1) ct=(ct-v+MOD)%MOD;
            else ct=(ct+v)%MOD;
        }
        long long ans = (pw[n]-ct+MOD)%MOD;
        return (int)ans;
    }
};
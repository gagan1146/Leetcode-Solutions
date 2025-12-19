// Last updated: 19/12/2025, 19:21:13
typedef long long ll;
class Solution {
public:
    vector<int> sieve(int n){
        vector<int> v(n+1,1);
        v[0]=0;
        v[1]=0;
        for(int i = 2;i<=sqrt(n);i++){
            if(v[i]){
                for(int j = i*i;j<=n;j+=i){
                    v[j]=0;
                }
            }
        }
        return v;
    }
    ll splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> p=sieve(n);
        ll sum1=0,sum2=0;
        for(int i = 0;i<n;i++){
            if(p[i]) sum1+=nums[i];
            else sum2+=nums[i];
        }
        return abs(sum1-sum2);
    }
};
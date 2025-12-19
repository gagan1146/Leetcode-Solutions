// Last updated: 19/12/2025, 19:21:12
class Solution {
public:
    using ll = long long;
    char processStr(string s, long long k) {
        ll n=0;
        for(auto &x: s){
            if(x=='*') n = max(0ll,n-1);
            else if(x=='#') n*=2;
            else if(x=='%') continue;
            else n++;
        }
        if(n<=k) return '.';
        reverse(s.begin(),s.end());
        for(auto &x:s){
            if(x=='*') n++;
            else if(x=='#'){
                n/=2;
                if(k>=n) k-=n;
            }
            else if(x=='%') k=n-k-1;
            else{
                n--;
                if(n<=k) return x;
            }
        }
        return '.';
    }
};
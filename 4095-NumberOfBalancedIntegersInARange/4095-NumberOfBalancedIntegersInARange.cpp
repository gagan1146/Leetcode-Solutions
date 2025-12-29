// Last updated: 29/12/2025, 21:48:35
class Solution {
public:
    long long dp[20][401][2][2][2];
    string s;
    int n;
    long long f(int p, int d,bool st,bool t,int par, int l){
        if(p==n) return (st&&l>=2&&d==200)?1:0;
        long long &res = dp[p][d][st][t][par];
        if(res!=-1) return res;
        res=0;
        int li = t?s[p]-'0':9;
        for(int d1=0;d1<=li;d1++){
            bool nst = st||(d1!=0);
            bool nt = t&&(d1==li);
            int nd = d,nl=l, npar=par;
            if(nst){
                nl++;
                if(par==0) nd+=d1;
                else nd-=d1;
                npar^=1;
            }
            if(nd>=0 && nd<=400) res += f(p+1,nd,nst,nt,npar,nl);
        }
        return res;
    }
    long long f1(long long x){
        if(x<10) return 0;
        s = to_string(x);
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return f(0,200,false,true,0,0);
    }
    long long countBalanced(long long low, long long high) {
        return f1(high)-f1(low-1);
    }
};
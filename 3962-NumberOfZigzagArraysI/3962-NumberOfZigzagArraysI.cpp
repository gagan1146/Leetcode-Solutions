// Last updated: 19/12/2025, 19:21:02
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int MOD =1e9+7;
        int m = r-l+1;
        if(m==1) return 0;
        vector<int>u(m,0),d(m,0);
        for(int i=0;i<m;i++){
            int v = i+l;
            u[i]=max(0,v-l);
            d[i]=max(0,r-v);
        }
        for(int i=3;i<=n;i++){
            vector<int>pr(m+1,0);
            for(int ind=0;ind<m;ind++)
                pr[ind+1]=(pr[ind]+d[ind])%MOD;
            vector<int>su(m+2,0);
            for(int ind=m-1;ind>=0;ind--)
                su[ind+1]=(su[ind+2]+u[ind])%MOD;
            vector<int>nu(m,0),nd(m,0);
            for(int ind=0;ind<m;ind++){
                nu[ind]=(ind>0)?pr[ind]:0;
                nd[ind]=(ind<m-1)?su[ind+2]:0;
            }
            u=std::move(nu);
            d=std::move(nd);
        }
        int t=0;
        for(int i=0;i<m;i++){
            t = (t+u[i])%MOD;
            t = (t+d[i])%MOD;
        }
        return t;
    }
};
// Last updated: 19/12/2025, 19:19:50
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size(), cn=0;
        vector<int>c(n),d(1);
        for(int i=0;i<n;i++){
            if(s[i]!='0'){
                cn++;
                d.push_back(s[i]-'0');
            }
            c[i]=cn;
        }
        const int m = 1000000007;
        vector<long long>p(cn+1),b(cn+1),ss(cn+1);
        p[0]=1;
        for(int i=1;i<=cn;i++){
            p[i]=p[i-1]*10%m;
            ss[i]=(ss[i-1]+d[i])%m;
            b[i]=(b[i-1]*10+d[i])%m;
        }
        int q = queries.size();
        vector<int>ans(q);
        for(int i=0;i<q;i++){
            int l = queries[i][0], r = queries[i][1], r1 = c[queries[i][1]];
            int x = (l==0?0:c[l-1])+1;
            if(r1<x){ans[i]=0;continue;}
            int len=r1-x+1;
            long long x1 = (b[r1]-b[x-1]*p[len])%m;
            if(x1<0) x1+=m;
            long long sm = (ss[r1]-ss[x-1])%m;
            if(sm<0)sm+=m;
            ans[i]=(int)(x1*sm%m);
        }
        return ans;
    }
};
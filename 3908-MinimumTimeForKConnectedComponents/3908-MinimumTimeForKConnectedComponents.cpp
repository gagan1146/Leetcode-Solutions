// Last updated: 19/12/2025, 19:21:19
class DSU{
    public:
    vector<int>pr,sz;
    DSU(int n){
        pr.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            pr[i]=i;
            sz[i]=1;
        }
    }
    int fxn1(int u){
        if(pr[u]!=u)pr[u]=fxn1(pr[u]);
        return pr[u];
    }
    void fxn2(int u,int v){
        int pu = fxn1(u);
        int pv = fxn1(v);
        if(pu!=pv){
            if(sz[pu]<sz[pv]) swap(pu,pv);
            pr[pv] = pu;
            sz[pu] +=sz[pv];
        }
    }
};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(),edges.end(), [](const vector<int>&a, const vector<int>& b){
            return a[2]<b[2];
        });
        int l=0,r=1000000000, ans=-1;
        while(l<=r){
            int md = l+(r-l)/2;
            DSU obj(n);
            int cmps = n;
            for(int i=edges.size()-1;i>=0;i--){
                if(edges[i][2]<=md) break;
                int u = edges[i][0], v=edges[i][1];
                if(obj.fxn1(u)!=obj.fxn1(v)){
                    obj.fxn2(u,v);
                    cmps--;
                }
            }
            if(cmps>=k){
                ans=md;
                r=md-1;
            }
            else l =md+1;
        }
        return ans;
    }
};
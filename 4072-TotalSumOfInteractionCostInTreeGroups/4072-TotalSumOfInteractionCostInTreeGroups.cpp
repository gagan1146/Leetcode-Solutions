// Last updated: 22/12/2025, 07:56:59
class Solution {
public:
    int n;
    vector<vector<int>>e;
    vector<int>g;
    long long ans;
    int dfs(int u, int p, int x, int t,vector<int>&g){
        int c = (g[u]==x);
        for(int v:e[u]){
            if(v==p) continue;
            int r = dfs(v,u,x,t,g);
            ans += (long long)r*(t-r);
            c+=r;
        }
        return c;
    }
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        e.assign(n,{});
        for(int i=0;i<n-1;i++){
            int u = edges[i][0], v = edges[i][1];
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int x=1;x<=20;x++){
            int t=0;
            for(int i=0;i<n;i++)t+=group[i]==x;
            if(t>1) dfs(0,-1,x,t,group);
        }
        return ans;
    }
};
// Last updated: 19/12/2025, 19:21:37
class Solution {
public:
    int fxn1(int u, vector<int>&pr){
        if(pr[u]!=u){
            pr[u] = fxn1(pr[u],pr);
        }
        return pr[u];
    }
    void fxn2(int u, int v, vector<int>&pr){
        int pu = fxn1(u,pr);
        int pv = fxn1(v,pr);
        if(pu!=pv) pr[pv]=pu;
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int>pr(c+1);
        for(int i=0;i<=c;i++) pr[i]=i;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            fxn2(u,v,pr);
        }
        unordered_map<int,set<int>>st;
        for(int i=1;i<=c;i++){
            int r = fxn1(i,pr);
            st[r].insert(i);
        }
        vector<bool>ol(c+1,true);
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int t = queries[i][0];
            int x = queries[i][1];
            int r = fxn1(x,pr);
            if(t==1){
                if(ol[x]){
                    ans.push_back(x);
                }
                else if(!st[r].empty()){
                    ans.push_back(*st[r].begin());
                }
                else{
                    ans.push_back(-1);
                }
            }
            else if(t==2){
                if(ol[x]){
                    ol[x]=false;
                    st[r].erase(x);
                }
            }
        }
        return ans;
    }
};
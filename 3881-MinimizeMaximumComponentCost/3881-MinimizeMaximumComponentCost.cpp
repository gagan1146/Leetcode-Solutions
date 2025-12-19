// Last updated: 19/12/2025, 19:21:33
class DSU{
   public:
    vector<int>parent;
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x){
        if(parent[x]!=x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y){
        int x1 = find(x), y1=find(y);
        if(x1==y1) return false;
        parent[y1]=x1;
        return true;
    }
};

bool comp(const vector<int>& a, const vector<int> &b){
    return a[2]<b[2];
}

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(),edges.end(),comp);
        DSU ob(n);
        vector<int>mst;
        for(auto &edge : edges){
            int u = edge[0], v=edge[1], w=edge[2];
            if(ob.unite(u,v)){
                mst.push_back(w);
            }
        }
        sort(mst.begin(), mst.end()); 
        if (mst.size() <= k - 1) return 0; 
        return mst[mst.size() - k];
    }
};
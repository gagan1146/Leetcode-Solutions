// Last updated: 19/12/2025, 19:20:44
int dsu[500]; 
int find(int x) { return dsu[x] < 0 ? x : dsu[x] = find(dsu[x]); }
bool join(int x, int y)
{
    int p = find(x), q = find(y);
    if(p == q) return 0;
    if (-dsu[p] < -dsu[q]) swap(p, q);  
    dsu[p] += dsu[q];
    dsu[q] = p;

    return 1;
}

class Solution {
public:
    int maxPartitionFactor(vector<vector<int>>& p) {
        memset(dsu, -1, sizeof(dsu));
        int n = p.size();
        vector<array<int, 3>> v;
        vector<bool> col(n);
        vector<vector<int>> g(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int len = abs(p[j][0] - p[i][0]) + abs(p[j][1] - p[i][1]);
                v.push_back({len, i, j});
            }
        }
        sort(v.begin(), v.end());
        auto dfs = [&](auto&& dfs, int x, int par) -> void{
            col[x] = !col[x];
            for(auto ch: g[x]) {
                if(ch == par) continue;
                dfs(dfs, ch, x);
            }
        };
        for(auto& ar: v) {
            int len = ar[0], p1 = ar[1], p2 = ar[2];
            int r1 = find(p1), r2 = find(p2);
            if(r1 == r2 && col[p1] != col[p2]) continue;
            else if(r1 == r2 && col[p1] == col[p2]) return len;
            else if(col[p1] != col[p2]) join(p1, p2);
            else {
                dfs(dfs, p2, -1);
                join(p1, p2);
            }
            g[p1].push_back(p2);
            g[p2].push_back(p1);
        }
        return 0;
    }
};
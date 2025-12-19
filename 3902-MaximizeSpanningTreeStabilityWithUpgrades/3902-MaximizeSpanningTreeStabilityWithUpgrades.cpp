// Last updated: 19/12/2025, 19:21:23
class Solution {
public:
    struct DSU {
        vector<int> e;
        DSU(int N) { e = vector<int>(N, -1); }

        int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

        bool sameSet(int a, int b) { return get(a) == get(b); }

        int size(int x) { return -e[get(x)]; }

        bool unite(int x, int y) {
            x = get(x), y = get(y);
            if (x == y) return 0;
            if (e[x] > e[y]) swap(x, y);
            e[x] += e[y];
            e[y] = x;
            return 1;
        }
    };

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU obj(n + 2);
        multiset<int> s;
        vector<vector<int>> can;
        for (auto &it : edges) {
            int a = it[0], b = it[1], c = it[2], d = it[3];
            if (d == 1) {
                s.insert(c);
                if (!obj.unite(a, b)) return -1;
            } else {
                can.push_back({c, a, b});
            }
        }
        sort(can.rbegin(), can.rend());
        multiset<int> updated;
        for (auto &it : can) {
            int c = it[0], a = it[1], b = it[2];
            if (obj.size(0) == n) break;
            if (obj.unite(a, b)) {
                if (k > 0) {
                    if (s.empty() || (*s.begin() > c)) {
                        k--;
                        updated.insert(c * 2);
                        s.insert(c * 2);
                    }
                } else {
                    if (!updated.empty()) {
                        int mx = *updated.rbegin();
                        s.erase(s.find(mx));
                        updated.erase(updated.find(mx));
                        mx /= 2;
                        s.insert(mx);
                        updated.insert(c * 2);
                        s.insert(c * 2);
                    } else {
                        s.insert(c);
                    }
                }
            }
        }
        if (obj.size(0) != n) return -1;
        return *s.begin();
    }
};
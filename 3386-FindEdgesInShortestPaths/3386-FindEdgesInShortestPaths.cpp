// Last updated: 19/12/2025, 19:24:11
class Solution {
public:
    vector<vector<pair<int,int>>> gr;
    vector<int> sdis, ddis;

    void dijkstra(int src, int n, bool isSrc) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> vis(n, false);
        pq.push({0, src});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            if (vis[node]) continue;
            vis[node] = true;

            if (isSrc) sdis[node] = dis;
            else ddis[node] = dis;

            for (auto child : gr[node]) {
                if (!vis[child.first]) {
                    pq.push({dis + child.second, child.first});
                }
            }
        }
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        gr = vector<vector<pair<int,int>>>(n);

        for (auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            gr[u].push_back({v, w});
            gr[v].push_back({u, w});
        }

        sdis = vector<int>(n, INT_MAX);
        ddis = vector<int>(n, INT_MAX);

        dijkstra(0, n, true);
        dijkstra(n - 1, n, false);

        long long shortestDis = sdis[n - 1];
        vector<bool> ans(m, false);

        for (int j = 0; j < m; j++) {
            int u = edges[j][0], v = edges[j][1], w = edges[j][2];
            if ((long long)sdis[u] + w + ddis[v] == shortestDis ||
                (long long)sdis[v] + w + ddis[u] == shortestDis)
                ans[j] = true;
        }

        return ans;
    }
};
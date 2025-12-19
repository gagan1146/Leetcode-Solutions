// Last updated: 19/12/2025, 19:21:45
class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int n = matrix.size(), m = matrix[0].length();

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        unordered_map<char, vector<int>> mp;
        unordered_map<int, bool> visited;
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char ch = matrix[i][j];
                if(isalnum(ch)) {
                    mp[ch].push_back(i * m + j);
                }
            }
        }

        if(isalnum(matrix[0][0])){
            for(auto &it : mp[matrix[0][0]]){
                q.push({it, 0});
                visited[it] = true;
            }
            mp[matrix[0][0]].clear(); 
        }
        else {
            q.push({0, 0});
            visited[0] = true;
        }

        while(!q.empty()) {
            int a = q.front().first;
            int mov = q.front().second;
            int x = a / m, y = a % m;
            q.pop();

            if(x == n - 1 && y == m - 1) return mov;

            for(int i = 0; i < 4; i++) {
                int xn = x + dirs[i].first, yn = y + dirs[i].second;
                int next = xn * m + yn;

                if(xn >= 0 && xn < n && yn >= 0 && yn < m && !visited[next] && matrix[xn][yn] != '#') {
                    char ch = matrix[xn][yn];

                    if(ch == '.') {
                        q.push({next, mov + 1});
                        visited[next] = true;
                    }
                    else {
                        for(auto &it : mp[ch]) {
                            if(!visited[it]) {
                                q.push({it, mov + 1});
                                visited[it] = true;
                            }
                        }
                        mp[ch].clear(); 
                    }
                }
            }
        }
        return -1;
    }
};
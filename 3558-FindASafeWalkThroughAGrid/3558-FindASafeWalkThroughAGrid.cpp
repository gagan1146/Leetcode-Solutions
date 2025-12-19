// Last updated: 19/12/2025, 19:23:38
class Solution {
public:
     bool canPossible(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        // 3D vector to track visited states (row, col, remaining health)
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(health + 1, false)));

        // Initialize BFS queue
        queue<pair<pair<int, int>, int>> Q;
        Q.push({{0, 0}, health-grid[0][0]});
        visited[0][0][health] = true;

        // Directions for moving in the grid (right, down, left, up)
        int dx[] = {0, 1, -1, 0};
        int dy[] = {1, 0, 0, -1};

        while (!Q.empty()) {
            auto [pos, currHealth] = Q.front();
            Q.pop();
            int row = pos.first;
            int col = pos.second;

            // Check if we've reached the bottom-right corner
            if (row == m - 1 && col == n - 1)
            {
                if(currHealth>0) return true;
            }

            // Explore all four possible directions
            for (int i = 0; i < 4; ++i) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                // Ensure the new position is within bounds
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                    // Calculate new health
                    int newHealth = (grid[nrow][ncol] == 1) ? currHealth - 1 : currHealth;

                    // Ensure new health is positive and the state has not been visited
                    if (newHealth > 0 && !visited[nrow][ncol][newHealth]) {
                        visited[nrow][ncol][newHealth] = true;
                        Q.push({{nrow, ncol}, newHealth});
                    }
                }
            }
        }

        return false; 
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        return canPossible(grid, health);
    }
};
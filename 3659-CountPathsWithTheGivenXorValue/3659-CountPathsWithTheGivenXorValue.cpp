// Last updated: 19/12/2025, 19:22:50
#include <vector>
using namespace std;

class Solution {
public:
    long long f(int ind1, int ind2, int c, vector<vector<int>>& grid, int m, int n, int k, vector<vector<vector<long long>>>& dp) {
        if (ind1 == m - 1 && ind2 == n - 1) {
            return (c ^ grid[ind1][ind2]) == k ? 1 : 0;
        }

        if (ind1 >= m || ind2 >= n) return 0;

        if (dp[ind1][ind2][c] != -1) return dp[ind1][ind2][c];

        long long down = (f(ind1 + 1, ind2, c ^ grid[ind1][ind2], grid, m, n, k, dp))%1000000007;
        long long right = (f(ind1, ind2 + 1, c ^ grid[ind1][ind2], grid, m, n, k, dp))%1000000007;

        return dp[ind1][ind2][c] = (down + right)%1000000007;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int max_xor = 16;  

        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(max_xor, -1)));

        long long a = f(0, 0, 0, grid, m, n, k, dp);
        return (a % 1000000007);
    }
};
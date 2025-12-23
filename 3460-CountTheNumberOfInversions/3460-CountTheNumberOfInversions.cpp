// Last updated: 23/12/2025, 21:47:31
class Solution {
public:
    int dp[301][401] = {};
    int dfs(int i, int j, int cnt, vector<vector<int>>& reqs) {
        if (j >= 0 && reqs[j][0] == i) {
            if (reqs[j][1] != cnt)
                return 0;
            --j;
        }
        if (i == 0 || i * (i + 1) / 2 < cnt)
            return cnt == 0;
        if (dp[i][cnt] == 0) {
            dp[i][cnt] = 1;
            for (int k = 0; k <= min(i, cnt); ++k)
                dp[i][cnt] =
                    (dp[i][cnt] + dfs(i - 1, j, cnt - k, reqs)) % 1000000007;
        }
        return dp[i][cnt] - 1;
    }
    int numberOfPermutations(int n, vector<vector<int>>& reqs) {
        sort(begin(reqs), end(reqs));
        return dfs(n - 1, reqs.size() - 1, reqs.back()[1], reqs);
    }
};
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            dp[0][i] = A[0][i];
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j] = min(min(j == 0 ? 0x3f3f3f3f : dp[i - 1][j - 1], j == n - 1 ? 0x3f3f3f3f : dp[i - 1][j + 1]), dp[i - 1][j]) + A[i][j];
        int minval = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i)
            minval = min(minval, dp[n - 1][i]);
        return minval;
    }
};
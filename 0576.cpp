class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(N + 1, 0)));
        dp[i][j][0] = 1;
        int dir[4][2] = {{0, 1}, {0, -1}, { -1, 0}, {1, 0}};
        int sum = 0;
        for (int k = 1; k <= N; ++k)
        {
            for (int x = 0; x < m; ++x)
            {
                for (int y = 0; y < n; ++y)
                {
                    for (int t = 0; t < 4; ++t)
                    {
                        int nx = x + dir[t][0], ny = y + dir[t][1];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                            dp[nx][ny][k] = (dp[x][y][k - 1] + dp[nx][ny][k]) % 1000000007;
                        else
                            sum = (sum + dp[x][y][k - 1]) % 1000000007;
                    }
                }
            }
        }
        return sum;
    }
};
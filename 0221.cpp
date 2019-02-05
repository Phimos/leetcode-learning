class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxarea = 0;
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                dp[i][j] = (matrix[i][j] == '1');
        for (int i = 0; i < n; ++i)
            if (dp[i][0] == 1)
                maxarea = 1;
        for (int j = 0; j < m; ++j)
            if (dp[0][j] == 1)
                maxarea = 1;
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (dp[i][j])
                    maxarea = max(maxarea, (dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1])));
        maxarea = maxarea * maxarea;
        return maxarea;
    }
};
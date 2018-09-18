class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		for (int i = 1; i < m + n - 1; ++i)
			for (int j = i >= m ? m-1 : i; j >= 0 && i - j < n; --j)
				grid[j][i-j] += min(j == 0 ? 0x7fffffff : grid[j - 1][i-j], i == j ? 0x7fffffff : grid[j][i-j-1]);
		return grid[m - 1][n - 1];
	}
};
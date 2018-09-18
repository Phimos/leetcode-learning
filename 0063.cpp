class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> paths(m + 1, vector<int>(n + 1,0));
		if (obstacleGrid[0][0])//第一个点就有障碍
			return 0;
		paths[1][1] = 1;
		for (int i = 3; i <= m + n; ++i)
			for (int j = i>m ? m : i - 1; j >0 && i - j <= n; --j)
				paths[j][i - j] =obstacleGrid[j-1][i-j-1]?0: paths[j - 1][i - j] + paths[j][i - j - 1];
		return paths[m][n];
	}
};
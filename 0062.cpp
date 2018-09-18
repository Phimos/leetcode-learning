class Solution {
public:
	int uniquePaths(int m, int n) {
		int paths[101][101] = { 0 };
		paths[1][1] = 1;
		for (int i = 3; i <= m + n; ++i)
			for (int j =i>m?m:i-1; j >0&&i-j<=n; --j)
				paths[j][i - j] = paths[j - 1][i - j] + paths[j][i - j - 1];
		return paths[m][n];
	}
};
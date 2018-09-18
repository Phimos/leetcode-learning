class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
		vector<vector<int>> res(n, vector<int>(n));
		int count = 0;
		for (int i = 0; i < n / 2; ++i)
		{
			int x = i, y = i;
			for (int j = 0; j < 4; ++j)
			{
				for (int k = 0; k < n - 2 * i - 1; ++k)
				{
					res[x][y] = ++count;
					x += dir[j][0];
					y += dir[j][1];
				}
			}
		}
		if (count + 1 == n * n)
			res[n / 2 ][n / 2 ] =++count;
		return res;
	}
};

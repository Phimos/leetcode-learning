class Solution {
private:
	vector<vector<string>> ans;
	vector<string> chessboard;
	vector<bool> diag, row, col, r_diag;
	void solve(int r,int n)
	{
		for (int i = 0; i < n; ++i)
		{
			if (!diag[i - r + n - 1] &&! r_diag[i + r] &&! col[i])
			{
				chessboard[r][i] = 'Q';
				diag[i - r + n - 1] = r_diag[i + r] = col[i] = true;
				if (r == n - 1)
					ans.push_back(chessboard);
				else
					solve(r + 1, n);
				chessboard[r][i] = '.';
				diag[i - r + n - 1] = r_diag[i + r] = col[i] = false;
			}
		}
		return;
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		chessboard=vector<string>(n, string(n, '.'));
		diag = vector<bool>(2 * n - 1, false);
		row = vector<bool>(n, false);
		col = vector<bool>(n, false);
		r_diag = vector<bool>(2 * n - 1, false);
		//diag[i]表示y-x+n-1所在的主对角线（左上到右下），r_diat[i]表示y+x表示的副对角线,（右上到左下）
		//以上为初始化
		solve(0, n);
		return ans;
	}
};

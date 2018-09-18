class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i)
		{
			vector<bool> check(9, false);
			for (int j = 0; j < 9; ++j)
			{
				if ('1' <= board[i][j] && board[i][j] <= '9')
				{
					if (check[board[i][j] - '0'])
						return false;
					else
						check[board[i][j] - '0'] = true;
				}
			}
		}
		for (int i = 0; i < 9; ++i)
		{
			vector<bool> check(9, false);
			for (int j = 0; j < 9; ++j)
			{
				if ('1' <= board[j][i] && board[j][i] <= '9')
				{
					if (check[board[j][i] - '0'])
						return false;
					else
						check[board[j][i] - '0'] = true;
				}
			}
		}
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				vector<bool> check(9, false);
				for (int m = 0; m < 3; ++m)
				{
					for (int n = 0; n < 3; ++n)
					{
						if ('1' <= board[i * 3 + m][j * 3 + n] && board[i * 3 + m][j * 3 + n] <= '9')
						{
							if (check[board[i * 3 + m][j * 3 + n] - '0'])
								return false;
							else
								check[board[i * 3 + m][j * 3 + n] - '0'] = true;
						}
					}
				}
			}
		}
		return true;
	}
};

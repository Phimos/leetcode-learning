class Solution {
public:
	int dir[4][2]{ {0,1},{1,0},{-1,0},{0,-1} };
	bool dfs(vector<vector<char>>&board,vector<vector<bool>>& check, string& word, int k,int x,int y)
	{
		if (k == word.length())
			return true;
		check[x][y] = true;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !check[nx][ny] && board[nx][ny] == word[k])
			{
				if (dfs(board, check, word, k + 1, nx, ny))
					return true;
			}
		}
		check[x][y] = false;
		return false;
	}
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (board[i][j] == word[0])
				{
					vector<vector<bool>> check(board.size(), vector<bool>(board[0].size(), false));
					if (dfs(board, check, word, 1, i, j))
						return true;
				}
			}
		}
		return false;
	}
}; 

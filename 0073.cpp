class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int row = matrix.size();
		if (!row)
			return;
		int col = matrix[0].size();
		if (!col)
			return;
		vector<bool> mark_row(row, false), mark_col(col, false);
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (!matrix[i][j])
				{
					mark_row[i] = true;
					mark_col[j] = true;
				}
			}
		}
		for (int i = 0; i < row; ++i)
		{
			if (mark_row[i])
			{
				for (int j = 0; j < col; ++j)
				{
					matrix[i][j] = 0;
				}
			}
		}
		for (int j = 0; j < col; ++j)
		{
			if (mark_col[j])
			{
				for (int i = 0; i < row; ++i)
				{
					matrix[i][j] = 0;
				}
			}
		}
		return;
	}
};

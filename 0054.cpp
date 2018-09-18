class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.size() && matrix[0].size())
		{
			int m = matrix.size(), n = matrix[0].size();
			int up = 0, down = m - 1, left = 0, right = n - 1;
			while (left <right && up < down)
			{
				for (int i = left; i < right; ++i)
					res.push_back(matrix[up][i]);
				for (int i = up; i < down; ++i)
					res.push_back(matrix[i][right]);
				for (int i = right; i > left; --i)
					res.push_back(matrix[down][i]);
				for (int i = down; i > up; --i)
					res.push_back(matrix[i][left]);
				left++;
				right--;
				up++;
				down--;
			}
			if (left == right && up <= down)
				for (int i = up; i <= down; ++i)
					res.push_back(matrix[i][left]);
			else if (up == down && left<right)
				for (int i = left; i <= right; ++i)
					res.push_back(matrix[up][i]);
		}
		return res;
	}
};
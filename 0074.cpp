class Solution {
public:
	int find_row(vector<vector<int>>& matrix, int target, int up, int down)
	{
		if (up + 1 >= down)
			return up;
		int mid = (up + down) / 2;
		if (matrix[mid][0] > target)
			return find_row(matrix, target, up, mid);
		else
			return find_row(matrix, target, mid, down);
	}
	bool check(vector<int>& nums, int target, int left, int right)
	{
		if (left >= right)
			return false;
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			return true;
		else if (nums[mid] < target)
			return check(nums, target, mid + 1, right);
		else
			return check(nums, target, left, mid);
	}
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()||matrix[0].empty())
			return false;
		int row = find_row(matrix, target, 0, matrix.size());
		return check(matrix[row], target, 0, matrix[row].size());
	}
};

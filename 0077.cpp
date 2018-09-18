class Solution {
public:
	vector<int> temp;
	vector<vector<int>> res;
	void combine_sum(int n, int k, int num, int pos)
	{
		if (k == num)
		{
			res.push_back(temp);
			return;
		}
		for (int i = pos; i <= n - k + num + 1; ++i)
		{
			temp.push_back(i);
			combine_sum(n, k, num + 1, i + 1);
			temp.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k) {
		combine_sum(n, k, 0, 1);
		return res;
	}
};

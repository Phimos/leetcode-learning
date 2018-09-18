class Solution {
private:
	vector<vector<int>> sets;
	vector<int> subset;
	void find_subset_n(vector<int>& nums,int k, int n)//第k位开始查找，总共有n位
	{
		for (int i = 0; nums.size() - (i + k)>= n - subset.size(); ++i)
		{
			subset.push_back(nums[k + i]);
			if (subset.size() == n)
				sets.push_back(subset);
			else
				find_subset_n(nums, k + i + 1, n);
			subset.pop_back();
		}
		return;
	}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sets.push_back(vector<int>{});
		for (int i = 1; i <= nums.size(); ++i)
		{
			subset.clear();
			find_subset_n(nums, 0, i);
		}
		return sets;
	}
}; 

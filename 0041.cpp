class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		int i = 0;
		while (i < n)
		{
			if (nums[i] != i + 1 && nums[i] > 0 && nums[i] <= n)
			{
				int k = nums[i] - 1;
				if (nums[k] == k + 1)
					++i;
				else
					swap(nums[i], nums[k]);
			}
			else
				++i;
		}
		for (int i = 0; i < n; ++i)
			if (nums[i] != i + 1)
				return i + 1;
		return n + 1;
	}
};
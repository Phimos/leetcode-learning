class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 2; ++i)
		{
			while (i != 0 && i < n - 3 && nums[i] == nums[i - 1])
				++i;
			if (nums[i] > 0)
				break;
			int left = i + 1, right = n - 1;
			while (left < right)
			{
				int sum = nums[i] + nums[left] + nums[right];
				if (sum > 0)
					--right;
				else if (sum < 0)
					++left;
				else
				{
					vector<int> temp{nums[i], nums[left], nums[right]};
					ans.push_back(temp);
					while (left != i + 1 && nums[left] == nums[left - 1])
						++left;
					while (right != n - 1 && nums[right] == nums[right + 1])
						--right;
				}
			}
		}
		return ans;
	}
};
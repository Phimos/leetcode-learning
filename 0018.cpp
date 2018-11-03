class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<vector<int>> ans;
		for (int i1 = 0; i1 < n - 3; ++i1)
		{
			while (i1 > 0 && nums[i1] == nums[i1 - 1])
				++i1;
			for (int i2 = i1 + 1; i2 < n - 2; ++i2)
			{
				while (i2 > i1 + 1 && nums[i2] == nums[i2 - 1])
					++i2;
				int left = i2 + 1, right = n - 1;
				while (left < right)
				{
					int sum = nums[i1] + nums[i2] + nums[left] + nums[right];
					if (sum < target)
					{
						++left;
						while (left < n && nums[left] == nums[left - 1])
							++left;
					}
					else if (sum > target)
					{
						--right;
						while (right >= 0 && nums[right] == nums[right] + 1)
							--right;
					}
					else
					{
						vector<int> temp{ nums[i1], nums[i2], nums[left], nums[right] };
						ans.push_back(temp);
						++left;
						while (left < n && nums[left] == nums[left - 1])
							++left;
						--right;
						while (right >= 0 && nums[right] == nums[right] + 1)
							--right;
					}
				}
			}
		}
		return ans;
	}
};
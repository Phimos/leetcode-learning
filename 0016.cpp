class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		int ans = 0x7fffffff;
		for (int i = 0; i < n - 2; ++i)
		{
			int left = i + 1, right = n - 1;
			while (left < right)
			{
				int sum = nums[i] + nums[left] + nums[right];
				ans = abs(ans - target) < abs(sum - target) ? ans : sum;
				if (sum < target)
					++left;
				else
					--right;
			}
		}
		return ans;
	}
};
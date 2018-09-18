class Solution {
public:
	int max_left(vector<int>& nums, int left, int right)
	{
		if (left >= right)
			return 0;
		int sum = 0;
		int max_sum=nums[left];
		for (int i = left; i < right;++i)
		{
			sum += nums[i];
			max_sum = max(max_sum, sum);
		}
		return max_sum;
	}
	int max_right(vector<int>& nums, int left, int right)
	{
		if (left >= right)
			return 0;
		int sum = 0;
		int max_sum = nums[right-1];
		for (int i = right-1; i >= left; --i)
		{
			sum += nums[i];
			max_sum = max(max_sum, sum);
		}
		return max_sum;
	}

	int max_sub(vector<int>& nums, int left, int right)
	{
		if (left + 1 == right)
			return  nums[left];
		int mid = (left + right) / 2;
		int mid_sum = max_right(nums, left, mid) + max_left(nums, mid, right);
		return max(mid_sum, max(max_sub(nums, left, mid), max_sub(nums, mid, right)));
	}
	int maxSubArray(vector<int>& nums) {
		return max_sub(nums, 0, nums.size());
	}
};

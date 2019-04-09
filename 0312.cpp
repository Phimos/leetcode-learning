class Solution {
public:
	int getScore(vector<vector<int>>& dp, vector<int>& nums, int left, int right)
	{
		if (dp[left][right])
			return dp[left][right];
		if (left + 1 == right)
			return 0;
		if (left + 2 == right)
			return dp[left][right] = nums[left] * nums[left + 1] * nums[right];
		for (int i = left + 1; i < right; ++i)
			dp[left][right] = max(dp[left][right], getScore(dp, nums, left, i) + getScore(dp, nums, i, right) + nums[left] * nums[i] * nums[right]);
		return dp[left][right];
	}
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		vector<int> temp(n + 2);
		temp[0] = temp[n + 1] = 1;
		for (int i = 0; i < n; ++i)
			temp[i + 1] = nums[i];
		vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
		return getScore(dp, temp, 0, n + 1);
	}
};
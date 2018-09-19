class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		int n = nums.size(), cnt = 0;
		sort(nums.begin(), nums.end());
		for (int i = n - 1; i > 1; --i)//最长边
		{
			int j = i - 1, k = 0; //j中间边，k最短边
			while (k < j)
			{
				if (nums[k] + nums[j] > nums[i])
				{
					cnt += j - k;
					--j;
				}
				else
				{
					++k;
				}
			}
		}
		return cnt;
	}
};
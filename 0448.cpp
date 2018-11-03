class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans;
		for (int i = 0; i < n; ++i)
		{
			int k = abs(nums[i]) - 1;
			if (nums[k] > 0)
				nums[k] = -nums[k];
		}
		for (int i = 0; i < n; ++i)
		{
			if (nums[i] > 0)
				ans.push_back(i + 1);
		}
		return ans;
	}
};
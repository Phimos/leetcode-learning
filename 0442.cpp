class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> ans;
		int n = nums.size();
		for (int i = 0; i < n; ++i)	//归位，有负数说明已经出现
		{
			int k = abs(nums[i]) - 1;
			if (nums[k] > 0)
				nums[k] = -nums[k];
			else
				ans.push_back(abs(nums[i]));
		}
		return ans;
	}
};
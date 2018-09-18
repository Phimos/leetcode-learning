class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int l = 0, r = nums.size();
		vector<int> ans;
		while (l < r)
		{
			int k = (l + r) / 2;
			if (nums[k] < target)
				l = k + 1;
			else
				r = k;
		}
		ans.push_back(l);
		l = 0, r = nums.size();
		while (l < r)
		{
			int k = (l + r) / 2;
			if (nums[k] <= target)
				l = k + 1;
			else
				r = k;
		}
		if (ans[0] == l)
			return vector<int>{-1, -1};
		else
		{
			ans.push_back(l - 1);
			return ans;
		}
	}
};
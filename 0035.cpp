class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int l = 0, r = nums.size();
		while (l < r)
		{
			int k = (l + r) / 2;
			if (nums[k] == target)
				return k;
			else if (nums[k] < target)
				l = k + 1;
			else
				r = k;
		}
		return r;
	}
}; 
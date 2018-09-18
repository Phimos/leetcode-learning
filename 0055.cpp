class Solution {
public:
	bool search(vector<int>& nums, int goal)
	{
		if (goal == 0)
			return true;
		for (int i = goal - 1; i >= 0; --i)
			if (nums[i] + i >= goal)
				return search(nums, i);
		return false;
	}
	bool canJump(vector<int>& nums) {
		if (nums.empty())
			return true;
		else
			return search(nums, nums.size() - 1);
	}
};

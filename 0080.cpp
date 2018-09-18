class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int count = 0;
		for (int i = 0, j = 0; j<nums.size(); ++j)
		{
			if (j - i <= 1 || nums[i] != nums[j])
			{
				if (nums[i] != nums[j])
					i = j;
				nums[count++] = nums[j];
			}
		}
		return count;
	}
};

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int count = 0;
		for (int i = 0, j = 0;j<nums.size(); ++j)
		{
			if (i == j || nums[i] != nums[j])
			{
				nums[count++] = nums[j];
				i = j;
			}
		}
		return count;
	}
};

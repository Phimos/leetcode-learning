class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.empty())
			return 0;
		unordered_set<int> temp;
		for (int i = 0; i < nums.size(); i++)
			temp.insert(nums[i]);
		int maxlen = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			int n = nums[i], len = 1;
			if (temp.count(n))
			{
				for (int j = n + 1; temp.count(j); j++)
				{
					temp.erase(j);
					++len;
				}
				for (int j = n - 1; temp.count(j) ; j--)
				{
					temp.erase(j);
					++len;
				}
			}
			maxlen = max(maxlen, len);
		}
		return maxlen;
	}
};
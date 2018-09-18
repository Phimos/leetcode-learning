class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> pos(256, -1);
		int start = 0;
		int max_length = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			int k = s[i];
			if (pos[k] >= start)
			{
				max_length = max(max_length, i - start);
				start =pos[k]+1;
				pos[k] = i;
			}
			else
			{
				pos[k] = i;
			}
		}
		max_length = max(max_length, (int)s.length() - start);
		return max_length;
	}
};

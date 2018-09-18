class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string common_prefix;
		if (strs.size() == 0)
			return common_prefix;
		else
		{
			for (int i = 0; i < strs[0].size(); ++i)
			{
				char c = strs[0][i];
				for (int j = 1; j < strs.size(); ++j)
				{
					if (strs[j][i] != c)
						return common_prefix;
				}
				common_prefix.push_back(c);
			}
		}
		return common_prefix;
	}
};

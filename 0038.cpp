class Solution {
public:
	string countAndSay(int n) {
		vector<string> count(n);
		count[0] = "1";
		for (int i = 1; i < n; ++i)
		{
			int num = 1;
			for (int j = 0; j < count[i - 1].size(); ++j)
			{
				if (j == count[i - 1].size() - 1 || count[i - 1][j + 1] != count[i - 1][j])
				{
					count[i] += to_string(num);
					count[i].push_back(count[i-1][j]);
					num = 1;
				}
				else
				{
					++num;
				}
			}
		}
		return count[n - 1];
	}
};
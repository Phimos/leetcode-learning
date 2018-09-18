class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		vector<vector<bool>> check(n, vector<bool>(n));
		string longeststring;
		longeststring.push_back(s[0]);
		for (int i = 0; i < n - 1; ++i)
		{
			check[i][i] = true;
			if (s[i] == s[i + 1])
			{
				check[i][i + 1] = true;
				longeststring = s.substr(i, 2);
			}
		}
		check[n - 1][n - 1] = true;
		for (int i = 2; i < n; ++i)
		{
			for (int j = 0; j + i < n; ++j)
			{
				if (check[j + 1][j + i - 1] && s[j] == s[j + i])
				{
					check[j][j + i] = true;
					longeststring = s.substr(j,i+1 );
				}
				else
					check[j][j + i] = false;
			}
		}
		return longeststring;
	}
};

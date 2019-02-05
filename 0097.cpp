class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
		if (len1 + len2 != len3)
			return false;
		vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= len1; ++i)
		{
			for (int j = 0; j <= len2; ++j)
			{
				if (!dp[i][j])
					continue;
				if (i < len1 && s1[i] == s3[i + j])
					dp[i + 1][j] = true;
				if (j < len2 && s2[j] == s3[i + j])
					dp[i][j + 1] = true;
			}
		}
		return dp[len1][len2];
	}
};
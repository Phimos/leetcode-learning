class Solution {
public:
	int numDistinct(string s, string t) {
		int ls = s.length(), lt = t.length();
		vector<vector<int>> dp(lt + 1, vector<int>(ls + 1, 0));
		for(int i=0;i<=ls;++i)
			dp[0][i]=1;
		for (int i = 1; i <= lt; ++i)
		{
			for (int j = i; j <= ls; ++j)
			{
				dp[i][j] = dp[i][j - 1];
				if (t[i-1] == s[j-1])
				{
					dp[i][j] += dp[i - 1][j - 1];
				}
			}
		}
		return dp[lt][ls];
	}
};
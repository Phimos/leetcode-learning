class Solution {
public:
	int getmatch(const string& S, int l)
	{
		int len = S.length();
		int cnt = 0;
		for (int i = l + 1; i < len; ++i)
		{
			if (S[i] == '(')
				--cnt;
			else
				++cnt;
			if (cnt == 1)
				return i;
		}
	}

	int count(const string& S, int l, int r)
	{
		if (l + 1 == r)
			return 1;
		else
		{
			int rr;
			rr = getmatch(S, l);
			if (rr == r)
				return 2 * count(S, l + 1, r - 1);
			else
				return count(S, l, rr) + count(S, rr + 1, r);
		}
	}

	int scoreOfParentheses(string S) {
		int len = S.length();
		return count(S, 0, len - 1);
	}
};
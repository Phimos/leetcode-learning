class Solution {
public:
	bool isBig(char c)
	{
		if ('A' <= c && c <= 'Z')
			return true;
		else
			return false;
	}
	bool detectCapitalUse(string word) {
		int n = word.length();
		if (isBig(word[0]))
		{
			if (n == 1)
				return true;
			else
			{
				for (int i = 2; i < n; ++i)
					if (isBig(word[i]) ^ isBig(word[i - 1]))
						return false;
				return true;
			}
		}
		else
		{
			for (int i = 1; i < n; ++i)
				if (isBig(word[i]))
					return false;
			return true;
		}
	}
};
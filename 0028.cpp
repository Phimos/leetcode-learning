class Solution {
public:
	void get_next(string& needle,vector<int>& next)
	{
		int i = 0, k = -1;
		next[0] = -1;
		while (i < needle.length()-1)
		{
			while (k >= 0 && needle[i] != needle[k])
			{
				k = next[k];
			}
			++i;
			++k;
			if (needle[i] == needle[k])
				next[i] = next[k];
			else
				next[i] = k;
		}
	}
	int strStr(string haystack, string needle) {
		if (needle.length()==0)//特判
			return 0;
		vector<int> next(needle.length() );
		get_next(needle, next);
		int i, j;
		for (i = 0, j = 0; i < haystack.length()&&j<needle.length();++i,++j)
		{
			if (haystack[i] != needle[j])
			{	
				j = next[j];
			}
		}
		if (j == needle.length())
			return i - needle.length();
		return -1;
	}
};

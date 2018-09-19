class Solution {
public:
	void convert(string& src, string& des)
	{
		for (auto c : src)
		{
			if (c == '#')
			{
				if (!des.empty())
					des.pop_back();
			}
			else
			{
				des.push_back(c);
			}
		}
	}
	bool backspaceCompare(string S, string T) {
		string ss, tt;
		convert(S, ss);
		convert(T, tt);
		return ss == tt;
	}
};
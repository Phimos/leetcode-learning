class Solution {
public:
	int lengthOfLastWord(string s) {
		while (s.back() == ' ')
			s.pop_back();
		int l = s.size(), i;
		for (i = l; i != 0 && s[i-1]!=' '; i--)
			;
		return l - i;
	}
};

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		vector<string> temp(numRows);
		bool down = false;
		for (int i = 0, j = 0; i<s.length(); ++i, down ? ++j : --j)
		{
			if (j == 0 || j == numRows - 1)
				down = !down;
			temp[j].push_back(s[i]);
		}
		string ans;
		for (auto str : temp)
			for (auto c : str)
				ans.push_back(c);
		return ans;
	}
};
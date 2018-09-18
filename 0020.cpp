class Solution {
public:
	bool isValid(string s) {
		stack<char> check;
		for (int i = 0; i < s.size(); ++i)
		{
			switch (s[i])
			{
			case ')':
				if (!check.empty() && check.top() == '(')
					check.pop();
				else
					return false;
				break;
			case ']':
				if (!check.empty() && check.top() == '[')
					check.pop();
				else
					return false;
				break;
			case '}':
				if (!check.empty() && check.top() == '{')
					check.pop();
				else
					return false;
				break;
			default:
				check.push(s[i]);
			}
		}
		if (check.empty())
			return true;
		else
			return false;
	}
};
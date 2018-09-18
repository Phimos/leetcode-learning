class Solution {
private:
	vector<string> parenthesis;
	void create(int n, int left, int right,string& s)
	{
		if (left == n&&right==n)
		{
			parenthesis.push_back(s);
		}
		else
		{
			if (left < n)
			{
				s.push_back('(');
				create(n, left + 1, right, s);
				s.pop_back();
			}
			if (left > right)
			{
				s.push_back(')');
				create(n, left, right + 1, s);
				s.pop_back();
			}
		}
		return;
	}
public:
	vector<string> generateParenthesis(int n) {
		string s;
		create(n, 0, 0, s);
		return parenthesis;
	}
};

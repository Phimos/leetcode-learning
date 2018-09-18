class Solution {
private:
	map<char, vector<char>> keypad;
	vector<string> letters;
	void combine(int k, string& digits, string& letter)
	{
		if (k == digits.size())
			letters.push_back(letter);
		else
			for (char i : keypad[digits[k]])
			{
				letter.push_back(i);
				combine(k + 1, digits, letter);
				letter.pop_back();
			}
		return;
	}
public:
	vector<string> letterCombinations(string digits) {
		keypad['2'] = vector<char>{ 'a','b','c' };
		keypad['3'] = vector<char>{ 'd','e','f' };
		keypad['4'] = vector<char>{ 'g','h','i' };
		keypad['5'] = vector<char>{ 'j','k','l' };
		keypad['6'] = vector<char>{ 'm','n','o' };
		keypad['7'] = vector<char>{ 'p','q','r','s' };
		keypad['8'] = vector<char>{ 't','u','v' };
		keypad['9'] = vector<char>{ 'w','x','y','z' };
		string letter;
		if (digits.size())
			combine(0, digits, letter);
		return letters;
	}
};


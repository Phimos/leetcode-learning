class Solution {
public:
	bool check(string& s,string& t)
	{
		int l=s.length();
		map<char,char> fun_char;
		for (int i = 0; i < l; ++i)
		{
			if(fun_char.find(s[i])==fun_char.end())
				fun_char[s[i]]=t[i];
			else if(fun_char[s[i]]!=t[i])
				return false;
		}
		return true;
	}
	bool isIsomorphic(string s, string t) {
		return check(s,t)&&check(t,s);
	}
};
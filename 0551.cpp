class Solution {
public:
	bool checkRecord(string s) {
		bool absented = false;
		int late_cnt = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == 'A')
				if (absented)
					return false;
				else
					absented = true;
			if (s[i] == 'L')
				++late_cnt;
			else
				late_cnt = 0;
			if (late_cnt > 2)
				return false;
		}
		return true;
	}
};
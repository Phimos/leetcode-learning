class Solution {
public:
	int findSubstringInWraproundString(string p) {
		int count = 0, sum = 0;
		vector<int> len(26, 0);
		for (int i = 0; i < p.length(); ++i)
		{

			if (i != 0 && (p[i] - p[i - 1] == 1 || (p[i] == 'a' && p[i - 1] == 'z')))
				++count;
			else
				count = 1;
			len[p[i] - 'a'] = max(len[p[i] - 'a'], count);
		}
		for (int i = 0; i < 26; ++i)
			sum += len[i];
		return sum;
	}
};
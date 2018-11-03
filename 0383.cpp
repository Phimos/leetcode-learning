class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		sort(ransomNote.begin(), ransomNote.end());
		sort(magazine.begin(), magazine.end());
		int n = ransomNote.length();
		int len = magazine.length();
		int i, j;
		for (i = 0, j = 0; i < n && j < len; ++i)
		{
			while (j < len && magazine[j] < ransomNote[i])
				++j;
			if (magazine[j] == ransomNote[i])
				++j;
			else
				break;
		}
		if (i == n)
			return true;
		else
			return false;

	}
};
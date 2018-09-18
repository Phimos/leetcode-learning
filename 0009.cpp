class Solution {
public:
	bool isPalindrome(int x) {
		int ans = 0,x0=x;
		if (x < 0)
			return false;
		while (x)
		{
			ans = ans*10+x%10;
			x /= 10;
		}
		return ans==x0;
	}
};
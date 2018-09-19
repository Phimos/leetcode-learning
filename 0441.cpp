class Solution {
public:
	int arrangeCoins(int n) {
		long long ln=n;
		return (-1 + sqrt(1 + 8 * ln)) / 2;
	}
};
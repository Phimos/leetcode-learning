class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int l = digits.size()-1;
		int k = l, remain=1;
		while (remain&&k>=0)
		{
			digits[k] += remain;
			if (digits[k] >=10)
			{
				remain = 1;
				digits[k--] -= 10;
			}
			else
				remain = 0;
		}
		if (remain)
			digits.insert(digits.begin(), 1);
		return digits;
	}
};

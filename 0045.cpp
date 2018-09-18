class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size()-1;
		vector<int> l, r;
		l.push_back(0);
		r.push_back(0);
		while (r.back() < n)
		{
			int left = l.back(), right = r.back();
			l.push_back(r.back() + 1);
			int temp = 0;
			for (int i = left; i <= right; ++i)
				temp = max(temp, i + nums[i]);
			r.push_back(temp);
		}
		return l.size() - 1;
	}
};

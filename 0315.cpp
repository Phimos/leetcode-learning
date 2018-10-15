class Solution {
public:
	struct NUM
	{
		int n, pos;
		NUM() {}
		NUM(int n, int pos) : n(n), pos(pos) {}
		bool operator<(const NUM& b)const
		{
			if (n != b.n)
				return n < b.n;
			else
				return pos < b.pos;
		}
	};
	vector<int> Arr;
	int n;
	int lowbit(int k)
	{
		return k & (-k);
	}
	void update(int k)
	{
		for (int i = k; i <= n; i += lowbit(i))
		{
			Arr[i] += 1;
		}
		return;
	}
	int getSum(int k)
	{
		int ans = 0;
		for (int i = k; i > 0; i -= lowbit(i))
		{
			ans += Arr[i];
		}
		return ans;
	}
	vector<int> countSmaller(vector<int>& nums) {
		n = nums.size();
		Arr.resize(n + 1, 0);
		vector<int> count(n);
		vector<NUM> temp;
		for (int i = 0; i < n; ++i)
		{
			temp.push_back(NUM(nums[i], i));
		}
		sort(temp.begin(), temp.end());
		for (int i = 0; i < n; ++i)
		{
			count[temp[i].pos] = i - getSum(temp[i].pos);
			update(temp[i].pos + 1);
		}
		return count;
	}
};
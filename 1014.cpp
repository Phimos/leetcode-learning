class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& A) {
		int l = A.size();
		int t = A[0];
		int ans = 0;
		for (int i = 1; i < l; ++i)
		{
			ans = max(ans, A[i] - i + t);
			t = max(t, A[i] + i);
		}
		return ans;
	}
};
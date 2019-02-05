class Solution {
public:
	long long NALL[100010];
	long long NAL[100010];
	long long NAP[100010];
	long long A[100010];
	long long AL[100010];
	long long ALL[100010];
	long long AP[100010];
	int checkRecord(int n) {
		NAP[0] = 1;
		const long long MOD = 1000000007;
		for (int i = 0; i < n; ++i)
		{
			NALL[i + 1] = (NALL[i + 1] + NAL[i]) % MOD;
			NAL[i + 1] = (NAL[i + 1] + NAP[i]) % MOD;
			AL[i + 1] = (AL[i + 1] + A[i] + AP[i]) % MOD;
			ALL[i + 1] = (ALL[i + 1] + AL[i]) % MOD;

			NAP[i + 1] = (NAP[i + 1] + NAL[i] + NAP[i] + NALL[i]) % MOD;
			AP[i + 1] = (AP[i + 1] + AP[i] + AL[i] + ALL[i] + A[i]) % MOD;

			A[i + 1] = (A[i + 1] + NAP[i] + NAL[i] + NALL[i]) % MOD;
		}
		long long ans = (NALL[n] + NAL[n] + NAP[n] + A[n] + AL[n] + ALL[n] + AP[n]) % MOD;
		return (int)ans;
	}
};
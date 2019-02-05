class Solution {
public:
    int dp[21][2000];
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S > 1000)
            return 0;
        memset(dp, 0, sizeof(dp));
        dp[0][nums[0]] = 2;
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j < 2000; ++j)
            {
                if (dp[i - 1][j])
                {
                    dp[i][abs(j + nums[i])] += dp[i - 1][j];
                    dp[i][abs(j - nums[i])] += dp[i - 1][j];
                }
            }
        }
        dp[nums.size() - 1][0] *= 2;
        return dp[nums.size() - 1][abs(S)] / 2;
    }
};
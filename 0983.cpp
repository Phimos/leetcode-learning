class Solution {
public:
    int dp[366];
    int mincost(int k, vector<int>& days, vector<int>&costs)
    {
        if (k < days[0])
            return 0;
        if (dp[k])
            return dp[k];
        if (!binary_search(days.begin(), days.end(), k))
            return dp[k] = mincost(k - 1, days, costs);
        int ans = 0x3f3f3f3f;
        ans = min(ans, mincost(k - 1, days, costs) + costs[0]);
        ans = min(ans, mincost(k - 7, days, costs) + costs[1]);
        ans = min(ans, mincost(k - 30, days, costs) + costs[2]);
        return dp[k] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, 0, sizeof(dp));
        return mincost(days.back(), days, costs);
    }
};
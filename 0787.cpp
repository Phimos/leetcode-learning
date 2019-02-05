class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> steps(n, 0);
        vector<int> cost(n, 0x3f3f3f3f);
        steps[src] = 0;
        cost[src] = 0;
        priority_queue<pair<int, int>> travel;
        travel.push(make_pair(0, src));
        while (!travel.empty())
        {
            pair<int, int> temp = travel.top();
            travel.pop();
            if (temp.first != cost[temp.second] || steps[temp.second] > K)
                continue;
            int u = temp.second;
            for (int i = 0; i < flights.size(); ++i)
            {
                if (flights[i][0] != u)
                    continue;
                int v = flights[i][1];
                if (flights[i][2] + cost[u] < cost[v])
                {
                    cost[v] = flights[i][2] + cost[u];
                    steps[v] = steps[u] + 1;
                    travel.push(make_pair(cost[v], v));
                }
            }
        }
        if (cost[dst] == 0x3f3f3f3f)
            return -1;
        else
            return cost[dst];
    }
};
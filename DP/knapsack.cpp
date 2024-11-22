int knapsack(int i, int cap, vector<int> &cost, vector<int> &profit, vector<vector<int>> &dp) {
    if (i < 0) return 0;
    if (cap < 0) return -INF;
    if (dp[i][cap] != -1) return dp[i][cap];
    return dp[i][cap] = max(
        profit[i] + knapsack(i-1, cap-cost[i], cost, profit, dp),
        knapsack(i-1, cap, cost, profit, dp)
    );
}

/*
 * LeetCode 714. 买卖股票的最佳时机含手续费（Best Time to Buy and Sell Stock with Transaction Fee）
 *
 * 【算法】动态规划 / 股票状态机 DP
 * 【题意】可以完成多次股票交易，但同时只能持有一股；每笔完整交易需要支付一次手续费 fee。
 *
 * 【状态定义】
 * dp[i][0]：第 i 天结束时持有股票所能获得的最大利润（Hold）。
 * dp[i][1]：第 i 天结束时不持有股票所能获得的最大利润（Cash）。
 * 注意：状态描述“日终是否持股”，不是“当天是否恰好买入/卖出”。
 *
 * 【初始化】
 * dp[0][0] = -prices[0]：第一天买入股票。
 * dp[0][1] = 0：第一天不操作，不持股。
 *
 * 【状态转移】
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
 *   -> 继续持有，或从昨天未持股转为今天买入。
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
 *   -> 继续不持股，或从昨天持股转为今天卖出并扣除手续费。
 *
 * 【易错点】
 * 1. 手续费每笔交易只扣除一次，本实现统一在卖出时扣除。
 * 2. dp[0][1] = 0，而不是负无穷：首日完全可以不操作。
 * 3. 与 LC0309 不同，本题没有冷冻期，只需要“持股/不持股”两个状态。
 * 4. 最终通常返回 dp[n-1][1]，表示交易完成后不持股的最大利润。
 *
 * 【复杂度】时间 O(n)，空间 O(n)；可滚动优化为 O(1) 空间。
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = -prices[0]; // 日终持股
        dp[0][1] = 0;          // 日终不持股

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }

        return dp[n - 1][1];
    }
};

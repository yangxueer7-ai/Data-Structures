/*
 * LeetCode 0309. 买卖股票的最佳时机含冷冻期
 * （Best Time to Buy and Sell Stock with Cooldown）
 * 难度：Medium
 * 算法：状态机动态规划（Hold / Sold / Rest）
 *
 * 【状态定义】
 * dp[i][0]：第 i 天结束后持有股票（Hold）的最大累计利润。
 * dp[i][1]：第 i 天刚卖出股票（Sold）的最大累计利润。
 * dp[i][2]：第 i 天未持股且当天没有卖出（Rest）的最大累计利润。
 *
 * 【状态转移】
 * Hold = max(昨天 Hold, 昨天 Rest - 今天价格)
 * Sold = 昨天 Hold + 今天价格
 * Rest = max(昨天 Rest, 昨天 Sold)
 * 卖出后的下一天不能买入，因此 Hold 不能从昨天 Sold 转移。
 *
 * 【初始化】
 * 第 0 天 Hold = -prices[0]（买入需要花钱）；
 * 第 0 天 Sold = INT_MIN/2（不可能在第一天卖出）；
 * 第 0 天 Rest = 0（不进行交易）。
 *
 * 【易错点】
 * - 股票买入是现金流出，持有态初始化为负价格。
 * - Sold 状态已包含卖出收入，转到 Rest 时不能再次加价格。
 * - 循环 i < n，最后一天是下标 n-1，不能访问 dp[n]。
 * - 最终返回未持股的 Sold/Rest 两态最大值。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)，可用滚动变量优化到 O(1)
 */

#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = static_cast<int>(prices.size());
        vector<vector<int>> dp(n, vector<int>(3, 0));

        dp[0][0] = -prices[0];
        dp[0][1] = INT_MIN / 2;
        dp[0][2] = 0;

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }

        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};

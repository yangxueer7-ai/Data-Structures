/*
 * LeetCode 121. Best Time to Buy and Sell Stock
 * 题目：买卖股票的最佳时机
 *
 * 核心思路：
 * 贪心
 * 只能进行一次买入和一次卖出，
 * 并且必须先买后卖。
 *
 * 遍历每一天时，维护两个信息：
 * minPrice：
 * 截止当前为止出现过的最低价格，
 * 表示“如果之前要买，最便宜可以买多少钱”。
 *
 * ans：
 * 截止当前为止能获得的最大利润。
 *
 * 对于第 i 天：
 *
 * 1. 更新历史最低价格
 *    minPrice = min(minPrice, prices[i]);
 *
 * 2. 假设今天卖出，计算利润
 *    profit = prices[i] - minPrice;
 *
 * 3. 更新最大利润
 *    ans = max(ans, profit);
 *
 * 核心：
 * 每一天都假设“今天卖出”，
 * 那么只需要知道此前出现过的最低买入价格。
 *
 * 维护历史最低价，枚举今天作为卖出日。
 *
 * 易错点：
 *
 * 1. 不能先卖后买。
 * 2. minPrice 必须只由当前及之前的价格更新。
 * 3. 如果一直下跌，最大利润就是 0。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution121 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if (n == 0) {
            return 0;
        }

        int minPrice = prices[0];
        int ans = 0;

        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);

            int profit = prices[i] - minPrice;

            ans = max(ans, profit);
        }

        return ans;
    }
};
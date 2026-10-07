/*
 * LeetCode 122. Best Time to Buy and Sell Stock II
 * 题目：买卖股票的最佳时机 II
 *
 * 核心思路：贪心。
 * 和 LC121 不同：
 * LC121 只能完成一次交易，
 * 所以目标是寻找一次最大的买卖差价。
 *
 * LC122 可以完成多次交易，
 * 所以不需要维护全局最低价和最高价，
 * 而是把所有“上涨区间”的利润全部吃干抹净😋。
 *
 * 对于相邻两天：
 *
 * 如果：
 * prices[i] > prices[i - 1]
 *
 * 说明今天比昨天涨了，
 * 那么这一段上涨利润：prices[i] - prices[i - 1] 就可以直接加入答案。
 *
 * 为什么这样一定是全局最优？
 *
 * 因为一段连续上涨：
 *
 * a -> b -> c -> d
 *
 * 整段一次买卖的利润：
 *
 * d - a
 *
 * 等于每天上涨利润之和：
 *
 * (b - a) + (c - b) + (d - c)
 *
 * 所以“每天把上涨利润拿走”
 * 和“整段上涨一次吃完”收益完全一样。
 *
 * 而如果中间出现下跌：
 *
 * 例如：
 *
 * 1 -> 5 -> 3 -> 6
 *
 * 如果只看全局最低价和最高价：
 *
 * 6 - 1 = 5
 *
 * 但允许多次交易时：
 *
 * 1 -> 5：赚 4
 * 3 -> 6：赚 3
 *
 * 总利润 = 7
 *
 * 所以：
 * 上涨就赚，
 * 下跌就断开，
 * 把所有正利润累加起来。
 *
 * LC121：只找一次最大的涨幅。
 * LC122：所有正涨幅全部拿走。
 *
 * 易错点：
 *
 * 1. 不需要维护全局 minPrice / maxPrice。
 *
 * 2. 只累加正利润：
 *
 *    prices[i] - prices[i - 1] > 0
 *
 * 3. 如果一直下跌，答案自然为 0。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <vector>

using namespace std;

class Solution122 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                int profit = prices[i] - prices[i - 1];
                ans += profit;
            }
        }

        return ans;
    }
};
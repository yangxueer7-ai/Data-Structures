/*
 * LeetCode 322. Coin Change
 * 零钱兑换
 *
 * 算法：动态规划 / 完全背包 
 *
 * dp[j]：恰好凑出金额 j 所需的最少硬币数。
 *
 * 初始化：
 * dp[0] = 0，其他状态设为 INF = amount + 1。
 *
 * 状态转移：
 * dp[j] = min(dp[j], dp[j - x] + 1)
 *
 * 遍历顺序：
 * 外层枚举硬币，内层容量正序遍历。
 * 因为每种硬币可以无限次使用。
 *
 * 返回值：
 * 若 dp[amount] == INF，返回 -1；
 * 否则返回 dp[amount]。
 *
 * 时间复杂度：O(n * amount)
 * 空间复杂度：O(amount)
 *
 * 易错点：
 * 1. 完全背包容量正序遍历。
 * 2. 初始化不能全部设为 0。
 * 3. INF 需要避免加 1 时整数溢出。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution322 {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 设置合理的不可达标记，避免dp[j-x]+1溢出 以及dp[1]的不确定性
        // amount + 1 大于任何可能的最少硬币数
        // 最坏情况是使用amount个1元硬币，比这个还大就是不可达的情况
        const int INF = amount + 1;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int x : coins) {
            for (int j = x; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - x] + 1);
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};
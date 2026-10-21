/*
 * LeetCode 518. Coin Change II（零钱兑换 II）
 *
 * 算法：动态规划 + 完全背包（计数型）
 *
 * 核心思路：
 * 1. dp[j] 表示凑出金额 j 的组合数量。
 * 2. dp[0] = 1，表示不选任何硬币也是一种方案。
 * 3. 每种硬币可以无限次使用，因此属于完全背包。
 * 4. 状态转移：
 *      dp[j] += dp[j - x]
 *    不选当前硬币的方案 + 使用当前硬币新增的方案。
 * 5. 外层遍历硬币，内层正序遍历金额：
 *    - 硬币在外层：避免重复统计不同顺序的排列。
 *    - 金额正序：允许同一种硬币重复使用。
 *
 * 易错点：
 * 1. 本题求组合数量，不是最少硬币数。
 * 2. dp 初始化为 0，而不是 amount + 1。
 * 3. dp[0] 必须初始化为 1。
 * 4. 完全背包容量正序，0-1 背包容量倒序。
 * 5. 本题 int 版本在部分测试中会出现中间状态溢出。
 *    此处保留原始算法学习版本，实际 AC 使用 unsigned long long。
 *
 * 时间复杂度：O(n * amount)
 * 空间复杂度：O(amount)
 * n 为硬币面额的种类数。
 */


#include "LeetCodeCommon.h"

using namespace std;

class Solution518 {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        // 这题要求的是方案组合数 所以累加
        for (int x : coins) {
            for (int j = x; j <= amount; j++) {
                dp[j] = dp[j] + dp[j - x];
            }
        }

        return dp[amount];
    }
};
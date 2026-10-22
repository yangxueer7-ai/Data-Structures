/*
 * LeetCode 474. Ones and Zeroes（一和零）
 *
 * 算法：动态规划 + 二维容量 0-1 背包
 *
 * 核心思路：
 * 1. 每个字符串相当于一个物品，只能选择一次。
 * 2. 每个物品消耗两种资源：
 *    - zeros：字符串中 0 的数量
 *    - ones：字符串中 1 的数量
 * 3. 背包有两个容量限制：m 个 0、n 个 1。
 *
 * DP 状态定义：
 * dp[i][j] 表示最多使用 i 个 0 和 j 个 1，
 * 能够选择的最多字符串数量。
 *
 * 状态转移：
 * dp[i][j] = max(dp[i][j],
 *                dp[i-zeros][j-ones] + 1);
 *
 * - 不选当前字符串：dp[i][j]
 * - 选择当前字符串：
 *   消耗 zeros 个 0、ones 个 1，数量增加 1。
 *
 * 初始化：
 * dp 全部初始化为 0。
 * 因为不选择任何字符串也是合法方案。
 *
 * 易错点：
 * 1. 本题是 0-1 背包，每个字符串最多选一次。
 * 2. dp 的两个维度都是容量，不是物品下标。
 * 3. 两个容量都必须倒序遍历，避免重复选择当前字符串。
 * 4. dp[i][j] 求最多数量，所以使用 max()。
 * 5. 字符 '0' 和 '1' 是字符，不是整数 0 和 1。
 * 6. 允许 zeros=0 或 ones=0，循环边界仍然有效。
 *
 * 时间复杂度：O(L + k*m*n)
 * 空间复杂度：O(m*n)
 *
 * k 为字符串数量，L 为所有字符串的总长度。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        // dp[i][j]：最多使用 i 个0、j个1
        // 能够选择的最多字符串数量
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // 外层遍历每个字符串
        for (const string& s : strs) {
            int zeros = 0;
            int ones = 0;

            // 统计0 1个数
            for (char c : s) {
                if (c == '0') {
                    zeros++;
                }
                else {
                    ones++;
                }
            }

            // 均倒序遍历
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {

                    // 不选 vs 选
                    dp[i][j] = max(
                        dp[i][j],
                        dp[i - zeros][j - ones] + 1
                    );
                }
            }
        }

        return dp[m][n];
    }
};
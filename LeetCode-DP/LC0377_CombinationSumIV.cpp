/*
 * LeetCode 377. Combination Sum IV
 * 组合总和 IV
 *
 * 算法：动态规划 / 完全背包 / 排列计数
 *
 * 核心思路：
 * 1. nums 中的数字可以重复选择，属于完全背包问题。
 * 2. 本题要求统计凑出 target 的排列方案数。
 * 3. 与 LC518 不同，本题认为不同顺序是不同方案。(排列问题！）
 * 4. 因此外层遍历容量，内层遍历物品。
 * 5. 枚举每个数字 x 作为当前排列的最后一个元素。
 *
 * DP 状态：
 * dp[j] 表示使用 nums 中的数字，
 * 凑出总和 j 的排列方案数量。
 *
 * 初始化：
 * dp[0] = 1，表示空排列是凑出 0 的一种方案。
 * 其余状态初始化为 0，表示暂时没有方案。
 *
 * 状态转移：
 * 当 j >= x 时：
 * dp[j] += dp[j - x];
 *
 * 在所有凑出 j-x 的排列末尾添加一个 x，
 * 就能得到凑出 j 的新排列。
 *
 * 遍历顺序：
 * 外层：j = 1 到 target（容量正序）
 * 内层：遍历 nums 中的每个数字 x
 *
 * 为什么先遍历容量？
 * 因为需要统计排列数，不同顺序算不同方案。
 * 对于每个容量 j，枚举所有可能的最后一个数字。
 *
 * 与 LC518 的区别：
 * - LC518：组合计数，先物品后容量。
 * - LC377：排列计数，先容量后物品。
 * - 两者都使用 dp[j] += dp[j-x]。
 *
 * 时间复杂度：O(n * target)
 * 空间复杂度：O(target)
 *
 * 易错点：
 * 1. 本题统计排列数，而非组合数。
 * 2. 外层应遍历容量，内层遍历数字。
 *
 * 注意：
 * 本地 Git 归档保留最初的 int 版本，用于学习记录。
 * 某些测试用例的中间方案数可能超过 INT_MAX，
 * 导致有符号整数溢出，存在未定义行为。
 * LeetCode 平台 AC 版本已单独处理该问题。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution377 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[j] 表示凑出总和 j 的排列方案数
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        // 先容量，后物品：统计排列数
        for (int j = 1; j <= target; j++) {
            for (int x : nums) {
                if (j >= x) {
                    dp[j] += dp[j - x];
                }
            }
        }

        return dp[target];
    }
};
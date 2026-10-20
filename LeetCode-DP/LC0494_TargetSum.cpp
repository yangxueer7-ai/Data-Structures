/*
 * LeetCode 494. Target Sum
 * 目标和
 *
 * 算法：动态规划 / 0-1 背包 
 *
 * 核心思路：
 * 1. 将 nums 中的元素划分为正号部分 P 和负号部分 N。
 * 2. 根据 P + N = sum、P - N = target，
 *    推导出 P = (sum + target) / 2。
 * 3. 将问题转化为：从 nums 中选择若干元素，
 *    恰好凑出 bagSize 的方案数量。
 *
 * DP 状态：
 * dp[j] 表示从已经考虑的元素中，恰好凑出 j 的方案数。
 *
 * 初始化：
 * dp[0] = 1，表示什么都不选是一种方案。
 *
 * 状态转移：
 * dp[j] += dp[j - x]
 *
 * 遍历顺序：
 * 每个元素只能使用一次，因此容量必须倒序遍历。
 *
 * 返回值：
 * dp[bagSize]
 *
 * 时间复杂度：O(n * bagSize)
 * 空间复杂度：O(bagSize)
 *
 * 易错点：
 * 1. abs(target) > sum 时无解。
 * 2. sum + target 为奇数时无解。
 * 3. j >= x 才能选择当前元素，防止负下标。
 * 4. 一维 0-1 背包必须倒序遍历。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution494 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }

        // 无法凑够目标值
        if (abs(target) > sum) {
            return 0;
        }

        // 背包容量无法为整数
        if ((sum + target) % 2 != 0) {
            return 0;
        }

        int bagSize = (sum + target) / 2;

        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;

        for (int x : nums) {
            for (int j = bagSize; j >= x; j--) {
                dp[j] += dp[j - x];
            }
        }

        return dp[bagSize];
    }
};
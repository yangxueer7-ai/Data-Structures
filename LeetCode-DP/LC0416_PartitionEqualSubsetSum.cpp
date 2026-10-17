/*
 * LeetCode 416. 分割等和子集 (Partition Equal Subset Sum)
 * 难度：Medium
 * 算法：动态规划 / 0-1 背包 / 布尔型 DP
 *
 * 【题意】
 * 给定一个只包含正整数的数组 nums，
 * 判断是否能将数组划分为两个元素和相等的子集。
 * 每个元素只能使用一次，子集不要求连续。
 *
 * 【核心思路】
 * 1. 先计算数组总和 sum。
 * 2. 若 sum 为奇数，不可能平分，直接返回 false。
 * 3. 若 sum 为偶数，将问题转化为：
 *    能否从 nums 中选出若干元素，使其和恰好为 sum/2？
 *
 * 本质是 0-1 背包的可行性问题：
 * 每个数字只有「选」和「不选」两种情况。
 *
 * 【DP 状态定义】
 * dp[i][j]：只考虑前 i 个数字，
 *           能否选出若干元素，使其和恰好为 j。
 *
 * 【状态转移】
 * 当前考虑的数字为 x = nums[i-1]。
 *
 * ① 不选当前数字：
 *    dp[i-1][j]
 *
 * ② 选当前数字（前提 j >= x）：
 *    dp[i-1][j-x]
 *
 * ③ 综合判断：
 *    dp[i][j] = dp[i-1][j] || dp[i-1][j-x]
 *
 * 只要「选」或「不选」有一种方案成立，
 * dp[i][j] 就为 true。
 *
 * 【初始化】
 * 创建 (n+1) × (target+1) 的二维 DP 数组，
 * 初始值全部为 false。
 *
 * dp[i][0] = true：
 * 无论考虑前几个数字，都能通过不选任何元素凑出 0。
 *
 * dp[0][j] = false（j > 0）：
 * 一个数字都不选，无法凑出正数。
 *
 * 【遍历顺序】
 * i 从 1 到 n，枚举当前考虑的数字。
 * j 从 1 到 target，枚举目标重量。
 *
 * 最终返回 dp[n][target]。
 *
 * 【易错点】
 * 1. target = sum/2，不是再除以 2。
 * 2. dp[i][j] 中 i 表示前 i 个数字，
 *    因此当前数字是 nums[i-1]。
 * 3. 初始化 dp[i][0] 时应包含 i=n，
 *    即 for(int i=0; i<=n; i++)。
 * 4. 不能直接用「选当前数字」的结果覆盖「不选」的结果。
 *    必须使用逻辑或 ||，保留所有可行方案。
 * 5. 选当前数字时使用 dp[i-1][j-x]，
 *    因为每个元素只能使用一次。

 * 【复杂度】
 * 设 target = sum/2。
 * 时间复杂度：O(n*target)
 * 空间复杂度：O(n*target)

 * 分割等和子集 → 寻找和为 sum/2 的子集；
 * 0-1 背包通过「选或不选」判断目标和是否可达。
 *
 * 【后续复习】
 * 1. 二维 DP 状态转移的独立推导。
 * 2. 一维 DP 空间优化。
 * 3. 为什么 0-1 背包的一维容量必须倒序遍历。
 */

#include <vector>

using namespace std;

class Solution416 {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int x : nums) {
            sum += x;
        }

        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        vector<vector<bool>> dp(
            n + 1, vector<bool>(target + 1, false)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];

            for (int j = 1; j <= target; j++) {
                // 不选当前元素
                dp[i][j] = dp[i - 1][j];

                // 选当前元素
                if (j >= x) {
                    dp[i][j] =
                        dp[i][j] || dp[i - 1][j - x];
                }
            }
        }

        return dp[n][target];
    }
};
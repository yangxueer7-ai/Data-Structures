/*
 * LeetCode 1049. 最后一块石头的重量 II (Last Stone Weight II)
 * 难度：Medium
 * 算法：0-1 背包 / 二维布尔型 DP
 *
 * 【题意】
 * 给定若干块石头，每次选择两块进行粉碎，
 * 重量相等则全部消失，否则留下重量差。
 * 求最终可能剩下的最小重量。
 *
 * 【核心思路】
 * 将石头划分为两组，使两组重量之差尽可能小。
 * 设总重量为 sum，背包容量 target = sum / 2。
 * 只需要找到不超过 target 的最大可达重量 best。
 *
 * 最终答案：
 * ans = (sum - best) - best = sum - 2 * best
 *
 * 【DP 状态定义】
 * dp[i][j]：只考虑前 i 块石头，
 *           能否选出若干块，使重量之和恰好为 j。
 *
 * 【状态转移】
 * 当前石头重量 x = stones[i-1]。
 *
 * ① 不选当前石头：
 *    dp[i][j] = dp[i-1][j]
 *
 * ② 选当前石头（j >= x）：
 *    dp[i][j] = dp[i-1][j] || dp[i-1][j-x]
 *
 * 每块石头最多选一次，两种选择都来自上一行 i-1。
 *
 * 【初始化】
 * 创建 (n+1) × (target+1) 的 bool DP 数组，初始为 false。
 * dp[i][0] = true：不选任何石头，可以凑出重量 0。
 *
 * 【寻找最优解】
 * 从 target 向 0 倒序检查 dp[n][j]。
 * 第一个为 true 的位置，就是最大可达重量 best。
 * 找到后立即 break，避免被更小的重量覆盖。
 *
 * 【易错点】
 * 1. target = sum/2，只用于限制其中一组的最大重量。
 * 2. dp[i][j] 表示能否恰好凑出 j，而不是最大重量。
 * 3. 当前石头下标为 i-1，注意 DP 与数组下标偏移。
 * 4. 选与不选使用逻辑或 ||，不能覆盖已有可行方案。
 * 5. 只有 j >= x 才能选择当前石头，防止负下标。
 * 6. 初始化 dp[i][0] 时，i 应从 0 遍历到 n。
 * 7. 寻找 best 时倒序扫描，找到第一个 true 就 break。
 * 8. 本题倒序寻找 best 与一维 0-1 背包倒序更新
 *    是两种不同操作，不能混淆。
 *
 * 【与 LC416 对比】
 * LC416：判断能否恰好凑出 sum/2，返回 bool。
 * LC1049：寻找不超过 sum/2 的最大可达重量，
 *         返回 sum-2*best。
 *
 * 【复杂度】
 * 时间复杂度：O(n*target)
 * 空间复杂度：O(n*target)
 *
 * 将石头分成重量尽量接近的两组，
 * 二维 0-1 背包判断可达重量，倒序寻找 best。
 */

#include "LeetCodeCommon.h"

class Solution1049 {
public:
    int lastStoneWeightII(std::vector<int>& stones) {
        int n = stones.size();
        int sum = 0;

        for (int x : stones) {
            sum += x;
        }

        int target = sum / 2;

        std::vector<std::vector<bool>> dp(
            n + 1, std::vector<bool>(target + 1, false)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            int x = stones[i - 1];
            for (int j = 1; j <= target; j++) {
                dp[i][j] = dp[i - 1][j];

                if (j >= x) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - x];
                }
            }
        }

        int best = 0;

        for (int j = target; j >= 0; j--) {
            if (dp[n][j] == true) {
                best = j;
                break;
            }
        }

        return sum - 2 * best;
    }
};
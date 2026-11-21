/*
 * LeetCode 1025. 除数博弈（Divisor Game）
 * 难度：简单｜专题：博弈动态规划
 * 状态：2026-11-21 新题，LeetCode 已 AC
 *
 * 【题意】
 * Alice、Bob 轮流操作，Alice 先手。面对当前整数 i，玩家必须选择
 * 0 < x < i 且 i % x == 0，再将 i 变成 i - x。
 * 无法操作的人失败；双方都采用最优策略，判断先手能否获胜。
 *
 * 【状态定义】
 * dp[i]：轮到当前玩家、黑板上的数字为 i 时，是否存在必胜策略。
 * true 表示当前玩家可以获胜，false 表示无论如何操作都会失败。
 *
 * 【初始化】
 * dp[1] = false：i 为 1 时，没有合法真因数 x，当前玩家必败。
 * 其余状态先初始化为 false，等待枚举合法操作寻找必胜策略。
 *
 * 【状态转移】
 * 对每个 i（从 2 到 n），枚举 1 <= x < i：
 *   如果 i % x == 0，说明 x 是合法操作；
 *   如果 dp[i - x] == false，说明下一轮对手必败，
 *   因此 dp[i] = true，可以直接 break。
 * 若不存在这样的 x，dp[i] 保持 false。
 *
 * 【易错点】
 * - dp[i-x] 描述的是“下一轮轮到的玩家”，不是当前玩家。
 * 
 * - 存在一种操作使对手必败即可；不是要求所有 x 都满足。
 * 
 * - x 每轮都可以重新选择，并非固定值。
 * - 本文件保留博弈 DP 解法；本题也可由奇偶规律 O(1) 求解。
 *
 * 时间复杂度：O(n^2)，最坏枚举所有 i、x。
 * 额外空间复杂度：O(n)，布尔 DP 数组。
 *

 */
#include "LeetCodeCommon.h"

class Solution {
public:
    bool divisorGame(int n) {
        std::vector<bool> dp(n + 1, false);
        dp[1] = false;

        for (int i = 2; i <= n; i++) {
            for (int x = 1; x < i; x++) {
                if (i % x == 0 && dp[i - x] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

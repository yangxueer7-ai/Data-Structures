/*
 * LeetCode 70. Climbing Stairs
 *
 * Core:
 * dp[i] 表示到达第 i 阶的方法数。
 * 当前只能从 i-1 或 i-2 到达。
 *
 * 状态转移方程 State Transition:
 * dp[i] = dp[i-1] + dp[i-2]
 *
 * Complexity:
 * Time O(n)
 * Space O(1) after optimization
 *
 * 易错点：
 * n = 1 时不能直接访问 dp[2]。
 */

#include <vector>

using namespace std;

class Solution70 {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int prev2 = 1;
        int prev1 = 2;
        int cur = 0;

        for (int i = 3; i <= n; i++) {
            cur = prev1 + prev2;

            prev2 = prev1;
            prev1 = cur;
        }

        return cur;
    }
};
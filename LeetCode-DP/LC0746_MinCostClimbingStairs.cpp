/*
 * LeetCode 746. Min Cost Climbing Stairs
 *
 * Core:
 * dp[i] 表示到达位置 i 的最小花费。
 *
 * State Transition:
 * dp[i] = min(dp[i-2] + cost[i-2],
 *             dp[i-1] + cost[i-1])
 *
 * Complexity:
 * Time O(n)
 * Space O(1) after optimization
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution746 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        int cur = 0; // dp[i]
        for (int i = 2; i <= n; i++) {
            cur = min(prev2 + cost[i - 2], prev1 + cost[i - 1]);

            prev2 = prev1;
            prev1 = cur;
        }

        return cur;
    }
};
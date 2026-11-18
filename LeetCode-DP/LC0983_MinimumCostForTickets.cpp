/*
 * LeetCode 983. 最低票价（Minimum Cost For Tickets）
 *
 * 【算法】动态规划 / 最小费用型 DP（按自然日遍历）
 * 【题意】给出需要旅行的日期 days，及 1 天 / 7 天 / 30 天通行证费用，求覆盖所有旅行日的最少费用。
 *
 * 【核心区分】
 * 自然日：日历上的每一天；旅行日：days 数组中真正出行的日子。
 * 7 天票覆盖连续 7 个自然日，而非任意 7 个旅行日。
 *
 * 【状态定义】
 * dp[i]：截至自然日第 i 天，覆盖所有已发生旅行所需的最少费用。
 * isTravel[i]：第 i 个自然日是否需要出行。
 *
 * 【初始化】dp[0] = 0（尚无旅行，花费为 0）。
 *
 * 【状态转移】
 * 若第 i 天不旅行：dp[i] = dp[i-1]。
 * 若第 i 天旅行：
 *   1 天票：dp[i-1]              + costs[0]
 *   7 天票：dp[max(0, i-7)]      + costs[1]
 *  30 天票：dp[max(0, i-30)]     + costs[2]
 * 三种方案取最小值。
 *
 * 【易错点】
 * 1. 从 i=1 开始遍历，否则非旅行日可能访问 dp[-1]。
 * 2. i-7 和 i-30 可能小于 0，要用 max(0, ...) 保护下标。
 * 3. C++ 三个数求最小值应写 min({a,b,c})，不能写 min(a,b,c)。
 * 4. cur1、cur2、cur3 必须先声明类型。
 *
 * 【复杂度】设 D 为最后一个旅行日，m 为旅行日数量：
 *   时间 O(D+m)，空间 O(D+366)；题目中日期至多 365，可视作常数范围。
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<bool> isTravel(366, false);
        for (int day : days) {
            isTravel[day] = true;
        }

        int lastDay = days.back();
        vector<int> dp(lastDay + 1, 0);

        for (int i = 1; i <= lastDay; i++) {
            if (!isTravel[i]) {
                dp[i] = dp[i - 1];
            } else {
                int cur1 = dp[i - 1] + costs[0];
                int cur2 = dp[max(0, i - 7)] + costs[1];
                int cur3 = dp[max(0, i - 30)] + costs[2];
                dp[i] = min({cur1, cur2, cur3});
            }
        }

        return dp[lastDay];
    }
};

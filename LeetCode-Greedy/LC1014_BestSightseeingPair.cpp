/*
 * LeetCode 1014. 最佳观光组合（Best Sightseeing Pair）
 * 难度：中等｜专题：贪心、维护历史最优值
 * 状态：2026-11-21 新题，LeetCode 已 AC
 *
 * 【题意】
 * 选择两个不同景点 i < j，组合得分为：
 * values[i] + values[j] + i - j。
 * 求最大的组合得分。
 *
 * 【核心思路】
 * 把原式拆分为：
 *   (values[i] + i) + (values[j] - j)
 * 当第二个景点 j 固定时，只需找到 j 左侧最大的 values[i] + i。
 * 用 best 维护“历史上、当前 j 之前”的最大 values[i] + i；
 * 用 ans 维护到目前为止找到的最大组合得分。
 *
 * 【初始化】
 * best = values[0] + 0，初始的第一个候选景点是下标 0。
 * ans = INT_MIN，统一从 j=1 开始计算有效的两景点组合。
 *
 * 【更新顺序非常重要】
 * 1. 先 ans = max(ans, best + values[j] - j)：保证选中的 i < j；
 * 
 * 2. 再 best = max(best, values[j] + j)：把当前 j 加入后续候选。
 * 
 * 如果先更新 best，就可能把同一个 j 作为两个景点，违反 i < j。
 *
 * 【易错点】
 * - best 保存的是 values[i] + i 的最大“贡献值”，不是下标 i。
 * - 题目要求两个不同景点，j 从 1 开始。
 * - 不需要额外 DP 数组，只用历史最优变量即可。
 *
 * 时间复杂度：O(n)，单次线性扫描。
 * 额外空间复杂度：O(1)。
 *
 */
#include "LeetCodeCommon.h"

class Solution {
public:
    int maxScoreSightseeingPair(std::vector<int>& values) {
        int best = values[0] + 0;
        int ans = INT_MIN;

        for (int j = 1; j < static_cast<int>(values.size()); j++) {
            ans = std::max(best + values[j] - j, ans);
            best = std::max(best, values[j] + j);
        }

        return ans;
    }
};

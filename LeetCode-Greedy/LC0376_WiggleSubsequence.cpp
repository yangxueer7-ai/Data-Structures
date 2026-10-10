
/*
 * ============================================================
 * LeetCode 376. 摆动序列 (Wiggle Subsequence)
 * 难度：Medium
 * 专题：Greedy 
 *
 * 【核心思路】
 * 1. 摆动序列要求相邻差值正负交替。
 * 2. 连续上升时保留峰值，连续下降时保留谷值。
 * 3. 通过相邻差值的符号变化，统计最长摆动长度。
 * 4. 不需要实际构造子序列，只需维护变化方向。
 *
 * 【变量含义】
 * preDiff：上一次有效的变化方向。
 * curDiff：当前相邻两个元素的差值。
 * ans：当前最长摆动子序列的长度。
 *
 * 【贪心判断】
 * curDiff = nums[i] - nums[i - 1];
 *
 * if ((preDiff <= 0 && curDiff > 0) ||
 *     (preDiff >= 0 && curDiff < 0)) {
 *     ans++;
 *     preDiff = curDiff;
 * }
 *
 * preDiff 初始化为 0，表示尚未出现有效方向。
 * 允许 preDiff == 0，可以统计第一次上升或下降。
 *
 * 【为什么 curDiff 不能取等号？】
 * curDiff == 0 表示相邻元素相等，不产生摆动。
 * 因此只有 curDiff > 0 或 curDiff < 0 才能计数。
 *
 * 【易错点】
 * 1. preDiff 只在识别到有效新摆动时更新。
 *    否则平坡可能破坏之前记录的变化方向。
 * 2.初始 ans = 1，因为单个元素也是摆动序列。
 * 3. 连续上升或连续下降时，不重复计数。
 * 4. 相邻元素相等时，不增加答案。
 *
 * 【复杂度】
 * 时间：O(n)，只需遍历一次数组。
 * 空间：O(1)，只使用常数个辅助变量。
 *
 * 贪心保留峰谷，忽略平坡；
 * 只在上升与下降方向发生有效变化时计数。
 * ============================================================
 */

#include <vector>

using namespace std;

class Solution376 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int preDiff = 0;
        int curDiff = 0;
        int ans = 1; // 初始单个的数字也视作摆动序列

        for (int i = 1; i < n; i++) {
            curDiff = nums[i] - nums[i - 1];

            // 只有波谷（curDiff > 0）和波峰（curDiff < 0）才记录，
            // 这样摆动幅度维持会更稳
            // 贪心计算，从而获得最大的摆动子序列
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                ans++;
                preDiff = curDiff;
            }
        }

        return ans;

    }
};
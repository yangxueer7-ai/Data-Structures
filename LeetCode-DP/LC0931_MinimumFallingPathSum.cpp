/*
 * LeetCode 931. 下降路径最小和 (Minimum Falling Path Sum)
 * 题型：二维动态规划（自顶向下）
 *
 * 【题意】
 * 给定 n×n 矩阵，从第一行的任意格子出发，每次走到下一行的
 * 左下、正下或右下格子（不能越界），求到最后一行的最小路径和。
 *
 * 【状态定义】
 * dp[i][j]：从第一行任意位置出发，到达 matrix[i][j] 的最小路径和，
 *          包括当前位置 matrix[i][j] 的数值。
 *
 * 【初始化】
 * 第一行可任选起点，所以 dp[0][j] = matrix[0][j]。
 *
 * 【状态转移】
 * - 最左列 j == 0：从正上、右上转移。
 *   dp[i][0] = matrix[i][0] + min(dp[i-1][0], dp[i-1][1]);
 * - 最右列 j == n-1：从左上、正上转移。
 *   dp[i][n-1] = matrix[i][n-1]
 *              + min(dp[i-1][n-2], dp[i-1][n-1]);
 * - 中间列：从左上、正上、右上转移，三者取最小值。
 * 最终答案为最后一行 dp[n-1][j] 的最小值，而不是固定右下角。
 *
 * 【易错点】
 * - 第一行必须初始化为 matrix 的对应数值，不是全部设为 0。
 * - 第一列/最后一列不能访问不存在的左上/右上位置。
 * - 题目允许 n == 1：此时第二行起的循环不会执行，返回唯一元素。
 * - 最小路径和可以是负数，不要随意把答案初始设为 0。
 * - C++ 中 vector 二维数组声明后不要漏分号。
 *
 * 【复杂度】
 * 时间：O(n^2)，每个格子计算一次。
 * 额外空间：O(n^2)，使用二维 DP 表；可以另做滚动数组 O(n) 优化。
 *
 * 2026-11-20：LeetCode 平台已确认 AC。
 */
#include "LeetCodeCommon.h"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    dp[i][j] = matrix[i][0]
                        + min(dp[i - 1][j], dp[i - 1][j + 1]);
                }
                else if (j == n - 1) {
                    dp[i][j] = matrix[i][n - 1]
                        + min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
                else {
                    dp[i][j] = matrix[i][j]
                        + min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1] });
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[n - 1][i]);
        }

        return ans;
    }
};

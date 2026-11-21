/*
 * LeetCode 221. 最大正方形（Maximal Square）
 * 难度：中等｜专题：二维动态规划
 * 状态：2026-11-21 新题，修正后 LeetCode 已 AC
 *
 * 【题意】
 * 给定一个由字符 '0'、'1' 组成的 m×n 矩阵，
 * 求只包含 '1' 的最大正方形面积（注意不是边长）。
 *
 * 【状态定义】
 * dp[i][j]：以 (i,j) 作为右下角的最大全 1 正方形的“边长”。
 * maxLen：扫描过程中出现过的最大正方形边长。
 *
 * 【初始化】
 * 第一行、第一列最多只能形成边长 1 的正方形；
 * 按原矩阵赋值：dp[i][0] = matrix[i][0] - '0'，
 *              dp[0][j] = matrix[0][j] - '0'。
 * 初始化这两条边界时也必须更新 maxLen，兼容只有一行/一列的矩阵。
 *
 * 【状态转移】
 * 若 matrix[i][j] == '0'，则 dp[i][j] = 0。
 * 若 matrix[i][j] == '1'，则：
 *   dp[i][j] = 1 + min(dp[i-1][j],
 *                      dp[i-1][j-1],
 *                      dp[i][j-1]);
 * 即上、左上、左三个方向的最短板决定能扩展的正方形边长。
 * 最终返回 maxLen * maxLen（面积）。
 *
 * 【本次易错点】
 * - 不能把第一行/第一列的 dp 全部设为 1，要看 matrix 是否为 '1'。
 * 
 * - 判断原始格子时使用 matrix[i][j] == '1'，而不是 dp[i][j] == '1'；
 * 
 *   matrix 保存 char，dp 保存 int，含义和类型都不同。
 * 
 * - 初始化边界时记得更新 maxLen，以处理单行、单列、单元素情况。
 * - 返回的是面积，不是边长。
 *
 * 时间复杂度：O(mn)，每个格子处理一次。
 * 额外空间复杂度：O(mn)，二维 DP 数组。

 */

#include "LeetCodeCommon.h"

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        int maxLen = 0;

        // 第一列初始化
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] - '0';
            maxLen = std::max(maxLen, dp[i][0]);
        }

        // 第一行初始化
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j] - '0';
            maxLen = std::max(maxLen, dp[0][j]);
        }

        // 内部位置的状态转移
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = std::min({ dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1] }) + 1;
                    maxLen = std::max(dp[i][j], maxLen);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }

        return maxLen * maxLen;
    }
};

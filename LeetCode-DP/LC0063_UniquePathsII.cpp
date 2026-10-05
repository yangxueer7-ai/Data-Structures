/*
 * LeetCode 63. Unique Paths II
 * 题目：不同路径 II
 *
 * 核心思路：
 * 使用二维 DP。
 * dp[i][j] 表示从左上角 (0,0) 到达 (i,j) 的不同路径数。
 *
 * 状态转移：
 * 1. 如果 obstacleGrid[i][j] == 1：
 *      dp[i][j] = 0
 *
 * 2. 否则：
 *      dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
 *
 * 初始化：
 * - 若起点 obstacleGrid[0][0] == 1，直接返回 0
 * - dp[0][0] = 1
 * - 第一行只能从左边来
 * - 第一列只能从上面来
 *
 * 易错点：
 * 1. i / j 从 0 开始时，直接访问 i-1 / j-1 会越界
 * 2. 第一行 / 第一列中一旦遇到障碍物，后面的路径数会变成 0
 * 3. 最终答案是 dp[m - 1][n - 1]，不是把整个 dp 数组求和
 *
 * 时间复杂度：O(m * n)
 * 空间复杂度：O(m * n)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution63 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        dp[0][0] = 1;

        // 第一行初始化
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 1) {
                dp[0][j] = 0;
            }
            else {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // 第一列初始化
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
            }
            else {
                dp[i][0] = dp[i - 1][0];
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
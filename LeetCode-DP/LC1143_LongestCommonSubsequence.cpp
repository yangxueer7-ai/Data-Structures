/*
 * LeetCode 1143. 最长公共子序列
 * 难度：Medium
 * 专题：Dynamic Programming / String / LCS
 *
 * 核心思路：二维动态规划
 *
 * 一、状态定义
 * dp[i][j] 表示 text1 前 i 个字符与 text2 前 j 个字符
 * 的最长公共子序列（LCS）长度。
 *
 * 注意：子序列不要求连续，但必须保持原有相对顺序。
 *
 * 二、状态转移
 *
 * 1. 当前两个字符相等：
 *    text1[i-1] == text2[j-1]
 *
 *    dp[i][j] = dp[i-1][j-1] + 1;
 *
 *    两个字符都可以加入公共子序列，
 *    因此从左上角状态转移，再加 1。
 *
 * 2. 当前两个字符不相等：
 *
 *    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
 *
 *    分别考虑：
 *    - 舍弃 text1 当前字符：dp[i-1][j]
 *    - 舍弃 text2 当前字符：dp[i][j-1]
 *    选择其中较大的结果。
 *
 * 三、初始化
 *
 * vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
 *
 * 第一行和第一列均初始化为 0。
 * 因为任意字符串与空字符串的 LCS 长度都是 0。
 *
 * 四、遍历顺序
 *
 * for (int i = 1; i <= m; i++)
 *     for (int j = 1; j <= n; j++)
 *
 * 从左到右、从上到下填表。
 * 因为当前状态依赖左上、上方和左方状态。
 *
 * 五、本次易错点
 *
 * 1. 错误写法：text1[i] == text2[j]
 *    正确写法：text1[i-1] == text2[j-1]
 *
 *    原因：
 *    dp[i][j] 中的 i、j 表示前几个字符，
 *    而字符串下标从 0 开始。
 *
 * 2. dp 数组需要开 m+1 行、n+1 列，
 *    为两个空前缀保留初始状态。
 *
 * 3. 相等时从左上角 +1，
 *    不相等时从上方和左方取 max。
 *
 * 4. 最终答案是 dp[m][n]，
 *    表示两个完整字符串的 LCS 长度。
 *
 * 六、与其他题目的联系
 *
 * LC300：dp[i] 表示以 nums[i] 结尾的 LIS 长度。
 * LC1143：dp[i][j] 表示两个字符串前缀的 LCS 长度。
 *
 * 注意区分：
 * - 以 i 结尾：通常对应 nums[i]。
 * - 前 i 个元素：最后一个元素通常对应 nums[i-1]。
 *
 * 七、复杂度分析
 *
 * 时间复杂度：O(m*n)
 * 空间复杂度：O(m*n)
 */

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution1143 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};
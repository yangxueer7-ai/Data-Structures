/*
 * LeetCode 0516 - 最长回文子序列 (Longest Palindromic Subsequence)
 * 难度：Medium
 * 专题：动态规划 / 区间 DP / 字符串
 *
 * 题意：
 *   给定字符串 s，求其中最长回文子序列的长度。
 *   子序列可以跳过字符，但必须保持原有相对顺序；
 *   与「回文子串」不同，子序列不要求连续。
 *
 * 状态定义：
 *   dp[i][j] 表示闭区间 [i, j] 内最长回文子序列的长度。
 *
 * 初始化：
 *   单个字符本身是长度为 1 的回文子序列，因此 dp[i][i] = 1。
 *   其他位置初始为 0，也可用于表示长度为 0 的空区间。
 *
 * 状态转移：
 *   1. 若 s[i] == s[j]，可以同时选择两个端点：
 *          dp[i][j] = dp[i + 1][j - 1] + 2;
 * 
 *   2. 若 s[i] != s[j]，两个端点不能同时作为回文两端，
 *      分别尝试舍弃左端点或右端点，取更长的方案：
 *          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
 *
 * 遍历顺序：
 *   当前状态依赖 dp[i + 1][j - 1]、dp[i + 1][j] 和 dp[i][j - 1]。
 *   因此外层 i 从 n - 1 倒序到 0，保证下一行先计算；
 *   内层 j 从 i + 1 正序到 n - 1，保证左侧状态先计算。
 *
 * 易错点：
 *   - 本题求「最长长度」（int），不是判断区间是否回文（bool），
 *     也不是统计回文子串的数量（LC0647）。
 *   - 首尾相等时要 +2，把两个端点计入长度。
 *   - 首尾不相等时应取 max，而不是把两种方案相加。
 *   - dp[i][i] = 1，所以内层 j 从 i + 1 开始。
 *   - 当 j == i + 1 时，dp[i + 1][j - 1] 对应空区间，初始为 0，
 *     两个相等字符的结果就是 2；数组下标本身仍合法。
 *   - 最终答案为 dp[0][n - 1]，不是 dp[n - 1][n - 1]。
 *
 * 时间复杂度：O(n^2)，枚举全部合法区间。
 * 空间复杂度：O(n^2)，使用二维 DP 表。
 */

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

/*
 * LeetCode 0005. 最长回文子串
 * 难度：Medium
 * 分类：动态规划 / 区间 DP / 字符串
 *
 * 【题目描述】
 * 给定一个字符串 s，返回其中最长的回文子串。
 * 注意：子串必须连续，返回的是字符串本身，而不是长度。
 *
 * 【解题思路】
 * 使用二维区间动态规划判断每个子串是否为回文，
 * 同时记录最长回文子串的起始下标 start 和长度 maxLen。
 *
 * 【状态定义】
 * dp[i][j] 表示字符串区间 s[i...j] 整体是否为回文。
 * dp[i][j] = 1：是回文子串。
 * dp[i][j] = 0：不是回文子串。
 *
 * 【状态转移】
 * 1. 当 s[i] == s[j] 时：
 *    若 j - i <= 2，首尾相等即可判定为回文；
 *    否则需要判断内部区间 dp[i+1][j-1] 是否为回文。
 *
 * 2. 当 s[i] != s[j] 时：
 *    dp[i][j] = 0。
 *
 * 【初始化】
 * dp 数组初始化为 0。
 * dp[i][i] = 1，因为单个字符一定是回文。
 * start = 0，maxLen = 1。
 *
 * 【遍历顺序】
 * 外层 i 从 n-1 到 0 倒序遍历；
 * 内层 j 从 i+1 到 n-1 正序遍历。
 * 保证内部依赖状态 dp[i+1][j-1] 已经计算完成。
 *
 * 【答案更新】
 * 当区间为回文且长度 j-i+1 大于 maxLen 时，
 * 同时更新 start 和 maxLen。
 * 最终返回 s.substr(start, maxLen)。
 *
 * 【易错点】
 * 1. 不要遗漏 j-i <= 2 的短区间判断。
 * 2. start 和 maxLen 必须同步更新。
 * 3. substr 的第二个参数是长度，而非结束下标。
 * 4. 本题与 LC0647 的 DP 状态转移相同，
 *    但 LC0647 统计数量，本题记录最长区间。
 * 5. 不要与 LC0516 最长回文子序列的状态转移混淆。
 *
 * 【复杂度分析】
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n^2)
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int maxLen = 1;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = 1;
                    }
                }

                if (dp[i][j] && j - i + 1 > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

/*
 * LeetCode 0647 - 回文子串 (Palindromic Substrings)
 * 难度：Medium
 * 专题：动态规划 / 区间 DP / 字符串
 *
 * 题意：
 *   给定字符串 s，统计其中所有回文子串的数量。
 *   即使子串内容相同，只要出现位置不同，也需要分别计数。
 *
 * 状态定义：
 *   dp[i][j] 表示闭区间 [i, j] 对应的子串是否为回文串。
 *
 * 状态转移：
 *   1. 若 s[i] != s[j]，则 dp[i][j] = false。
 *   2. 若 s[i] == s[j] 且 j - i <= 2，说明子串长度不超过 3，
 *      其首尾相等就足以构成回文串，因此 dp[i][j] = true。
 *   3. 若 s[i] == s[j] 且 j - i > 2，则还需判断内部子串：
 *          dp[i][j] = dp[i + 1][j - 1]。
 *   4. 每遇到一个 dp[i][j] 为 true 的区间，就让 ans 加 1。
 *
 * 遍历顺序：
 *   dp[i][j] 依赖下一行的 dp[i + 1][j - 1]，因此外层 i 从 n - 1
 *   倒序遍历到 0；内层 j 从 i 正序遍历到 n - 1，枚举所有合法区间。
 *
 * 易错点：
 *   - 子串长度是 j - i + 1，所以短区间条件为 j - i <= 2。
 *   - 单个字符也是回文子串，因此 j 必须从 i 开始。
 *   - 只有 j - i > 2 时才访问 dp[i + 1][j - 1]，避免无效区间。
 *   - 判断布尔值可写 if (dp[i][j])，不要把 == 误写成赋值符号 =。
 *   - dp 初始全为 false，首尾不相等时无需再次赋值。
 *
 * 时间复杂度：O(n^2)，枚举所有起止下标的合法组合。
 * 空间复杂度：O(n^2)，使用二维布尔 DP 表。
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

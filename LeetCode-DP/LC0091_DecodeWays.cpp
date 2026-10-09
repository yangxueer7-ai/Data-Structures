/*
 * LeetCode 91. 解码方法 (Decode Ways)
 * 难度：Medium
 *
 * 【核心思路】
 * dp[i]：前 i 个字符的合法解码方案数。
 *
 * 1. 最后一位合法 (1~9)：dp[i] += dp[i-1]
 * 2. 最后两位合法 (10~26)：dp[i] += dp[i-2]
 *
 * 【初始化】
 * dp[0] = 1
 * dp[1] = s[0] == '0' ? 0 : 1
 *
 * 【易错点】
 * 1. 0 不能单独解码，只能组成 10 或 20。
 * 2. 两种转移条件独立判断。
 * 3. dp[i] 表示前 i 个字符，s[i-1] 才是最后一位。
 * 4. 方案计数使用 +=，不是 max()。
 *
 * 【复杂度】
 * 时间 O(n)，空间 O(n)
 */

#include <string>
#include <vector>

using namespace std;

class Solution91 {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;

        for (int i = 2; i <= n; i++) {
            // 最后一位是合法的，继承前面的方式数，前面的合法方式都可以将其接上
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // 最后两位都合法，一起解码 判断是不是在10~26范围内
            // 如果是，前面的合法方式都可以将其接上
            // s[i] - '0' 将字符转换为数字
            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (num >= 10 && num <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};
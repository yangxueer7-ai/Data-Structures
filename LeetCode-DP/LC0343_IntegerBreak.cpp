/*
 * LeetCode 0343. 整数拆分（Integer Break）
 * 难度：Medium
 * 算法：一维动态规划
 *
 * 【状态定义】
 * dp[i]：将整数 i 拆成至少两个正整数时可得到的最大乘积。
 *
 * 【状态转移】
 * 枚举第一个拆出的数 j，剩余 i-j 有两种处理方式：
 * 
 * 1. 不再拆分：j * (i - j)
 * 2. 继续拆分：j * dp[i - j]
 * 对所有 j 维护最大值：
 * dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]))。
 *
 * 【初始化】
 * dp[2] = 1，因为 2 只能拆为 1+1，乘积为 1。
 *
 * 【易错点】
 * - 不能只用当前 j 的两种方案覆盖 dp[i]，必须保留此前 j 的最优值。
 * - i 从 3 遍历到 n，j 从 1 遍历到 i-1。
 * - 必须比较“剩余数不再拆分”和“剩余数继续拆分”两种情况。
 *
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n)
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }

        return dp[n];
    }
};

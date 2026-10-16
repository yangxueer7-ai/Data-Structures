/*
 * LeetCode 718. 最长重复子数组 (Maximum Length of Repeated Subarray)
 * 难度：Medium
 * 算法：动态规划 / 二维 DP / 最长公共连续子数组
 *
 * 【题意】
 * 给定两个整数数组 nums1 和 nums2，
 * 返回两个数组中最长公共连续子数组的长度。
 *
 * 【核心思路】
 * dp[i][j] 表示
   以 nums1[i-1] 和 nums2[j-1] 结尾的最长公共连续子数组长度。
 * 因为要求连续，所以元素不相等时必须清零。
 * 使用 ans 记录遍历过程中出现的最大长度。
 *
 * 【状态转移】
 * 1. 如果 nums1[i-1] == nums2[j-1]：
 *    dp[i][j] = dp[i-1][j-1] + 1
 * 2. 否则：
 *    dp[i][j] = 0
 * 3. ans = max(ans, dp[i][j])
 *
 * 【初始化与遍历】
 * 1. 创建 (m+1) × (n+1) 的 dp 数组，初始化为 0。
 * 2. 第 0 行和第 0 列表示空前缀，无需单独初始化。
 *
 * 【易错点】
 * 1. dp[i][j] 对应 nums1[i-1]、nums2[j-1]，
 *    不能直接使用 nums1[i]、nums2[j]。
 * 2. 循环条件为 i<=m、j<=n，不能漏掉最后一个元素。
 *
 * 【与 LC1143 的区别】
 * LC1143：最长公共子序列，不要求连续。
 *          不相等时取 max(dp[i-1][j], dp[i][j-1])。
 * LC718 ：最长公共子数组，要求连续。
 *          不相等时直接清零。
 *
 * 【复杂度】
 * 时间复杂度：O(m*n)
 * 空间复杂度：O(m*n)
 *
 * 相同则左上角 +1，不同则清零，
 * 全局维护 ans，注意 DP 下标比数组下标大 1。
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution718 {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int ans = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // dp[i][j]表示以nums1[i-1] nums2[j-1]结尾的最长公共子数组的长度
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }

        return ans;
    }
};
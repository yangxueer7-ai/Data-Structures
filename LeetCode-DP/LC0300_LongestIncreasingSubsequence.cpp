/*
 * LeetCode 300. 最长递增子序列
 * 难度：Medium
 * 专题：Dynamic Programming / LIS
 *
 * 核心思路：动态规划 O(n²)
 *
 * 1. 状态定义：
 *    dp[i] 表示以 nums[i] 结尾的最长严格递增子序列长度。
 *
 * 2. 状态转移：
 *    枚举所有 j < i 的位置。
 *    如果 nums[j] < nums[i]，说明 nums[i] 可以接在
 *    以 nums[j] 结尾的递增子序列后面。
 *
 *    dp[i] = max(dp[i], dp[j] + 1);
 *
 * 3. 初始化：
 *    vector<int> dp(n, 1);
 *    因为每个元素自身都能构成长度为 1 的子序列。
 *
 * 4. 最终答案：
 *    ans = max(ans, dp[i]);
 *
 * 本次易错点：
 * - 初始 ans 写成 0，且外层循环从 i=1 开始，
 *   导致 nums 只有一个元素时返回 0。
 * - 本题保证 nums 非空，因此 ans 应初始化为 1。
 * - dp[i] 是以 i 结尾的 LIS，不是前 i 个元素的 LIS。
 *
 *
 * 时间复杂度：O(n²)，双重循环。
 * 空间复杂度：O(n)，使用一维 dp 数组。
 *
 * TODO：二分查找专题复盘！
 * - 学习贪心 + 二分查找解法。
 * - 理解 tails 数组维护最小结尾的思想。
 * - 掌握 lower_bound()。
 * - 将时间复杂度优化为 O(n log n)。
 *
 * 以当前元素为结尾，向前寻找所有比它小的元素，
 * 选择其中最长的递增子序列，再加上当前元素。
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution300 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i]表示以nums[i]结尾的最长子序列的长度
        vector<int> dp(n, 1);

        int ans = 1;
        for (int i = 1; i < n; i++) {
            // j在i之前，如果nums[j]<nums[i]
            // 符合条件，可以接上长度
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
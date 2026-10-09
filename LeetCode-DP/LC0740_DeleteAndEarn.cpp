/*
 * ============================================================
 * LeetCode 740. 删除并获得点数 (Delete and Earn)
 * 难度：Medium
 * 打家劫舍变形
 *
 * 【核心思路】
 * 1. 预处理：sum[x] += x，统计数值 x 的总点数。
 * 2. 选择 x 后不能选择 x-1 和 x+1。
 * 3. 将问题转化为 LC198 打家劫舍。
 *
 * 【DP 状态】
 * dp[i]：仅考虑数值 0 ~ i 时能够获得的最大点数。
 *
 * 【状态转移】
 * dp[i] = max(dp[i-1], dp[i-2] + sum[i])
 *
 * 【初始化】
 * dp[0] = 0
 * dp[1] = sum[1]
 *
 * 【复杂度】
 * 时间：O(n + M)
 * 空间：O(M)
 * n 为 nums 长度，M 为 nums 中最大值。
 *
 * 【易错点】
 * 1. dp 下标表示数字的值，而不是原数组下标。
 * 2. sum 长度为 maxVal + 1，避免下标越界。
 * 3. dp[1] = sum[1]，不一定等于 1。
 * 4. sum[x] += x 类似 MySQL GROUP BY + SUM。
 *
 * 先按数值聚合，再在数值轴上打家劫舍。
 * ============================================================
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution740 {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());

        // sum数组表示某一元素的累计点数
        vector<int> sum(maxVal + 1, 0);

        for (int x : nums) {
            sum[x] += x;
        }

        vector<int> dp(maxVal + 1);
        dp[0] = 0;
        dp[1] = sum[1];

        for (int i = 2; i <= maxVal; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + sum[i]);
        }

        return dp[maxVal];
    }
};
/*
 * LeetCode 213. House Robber II
 * 题目：打家劫舍 II
 *
 * ============================================================
 * 核心思路：
 * 环形 DP = 拆成两个线性 DP。
 * ============================================================
 *
 * 和 LC198 不同：
 *
 * LC198 的房屋是一条直线，
 * LC213 的房屋首尾相连形成一个环。
 *
 * 因此：
 * nums[0] 和 nums[n - 1] 不能同时偷。
 *
 * 所以最优解一定属于下面两种情况之一：
 * 情况 1：
 * 不偷最后一间房，
 * 只考虑区间：
 * [0, n - 2]
 *
 * 情况 2：
 * 不偷第一间房，
 * 只考虑区间：
 * [1, n - 1]
 *
 * 分别对这两个区间做一次
 * 最后取两者最大值：
 * max(
 *     robRange(nums, 0, n - 2),
 *     robRange(nums, 1, n - 1)
 * )
 *
 * ============================================================
 * robRange 辅助函数
 * ============================================================
 *
 * robRange(nums, left, right)
 *
 * 表示：
 * 只考虑 nums[left] ~ nums[right] 这一段房屋，
 * 求最多能偷多少钱。
 *
 * 使用滚动 DP：
 * prev2：
 * 表示处理到前前一间房时的最大金额。
 *
 * prev1：
 * 表示处理到前一间房时的最大金额。
 *
 * 对于当前房屋 nums[i]：
 *
 * 1. 不偷当前房：
 *    prev1
 * 2. 偷当前房：
 *    prev2 + nums[i]
 *
 * 所以：cur = max(prev1, prev2 + nums[i])
 *
 * 然后滚动更新：
 *
 * prev2 = prev1;
 * prev1 = cur;
 * 最后返回 prev1。
 *
 * ============================================================
 * 易错点
 * ============================================================
 *
 * 1. robRange 的 right 是包含在区间里的，
 *    所以循环应该：
 *
 *    i <= right
 *
 *    不能写成 i < right。
 *
 * 2. 首尾不能同时偷，
 *    但并不代表必须偷其中一个。
 *
 * 3. 这题不是简单找最大房屋，
 *    因为局部最大不一定组成全局最优。
 * 因为可能去顾及局部最大，会忽视相邻房屋的限制，导致全局最优解被错过
 * 4. 辅助函数本质就是 LC198 的滚动 DP。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <vector>

using namespace std;

class Solution213 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // 最多只有3个房屋的时候，只能偷一个最大的    
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        if (n == 3) return max(nums[0], max(nums[1], nums[2]));

        int ans1 = robRange(nums, 0, n - 2);
        int ans2 = robRange(nums, 1, n - 1);

        return max(ans1, ans2);
    }

    int robRange(vector<int>& nums, int left, int right) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = left; i <= right; i++) {
            int cur = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};
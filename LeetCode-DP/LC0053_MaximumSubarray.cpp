/*
 * LeetCode 53. Maximum Subarray
 * 题目：最大子数组和
 *
 * ============================================================
 * 解法一：DP 数组
 * ============================================================
 *
 * 状态定义：
 * dp[i] 表示：
 * 以 nums[i] 结尾的最大连续子数组和。
 *
 * 状态转移：
 *
 * 对于当前位置 nums[i]，有两种选择：
 *
 * 1. 接在前面的连续子数组后面
 *    dp[i - 1] + nums[i]
 *
 * 2. 前面的部分不要了，从 nums[i] 重新开始
 *    nums[i]
 *
 * 所以：
 *
 * dp[i] = max(dp[i - 1] + nums[i], nums[i])
 *
 * 初始化：
 * dp[0] = nums[0]
 * 注意：
 * dp[i] 只表示“以 i 结尾”的最大和，
 * 并不代表整个数组的最终答案。
 *
 * 因此需要使用 ans 记录所有 dp[i] 中的最大值。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 *
 * ============================================================
 * 解法二：空间优化 / Kadane 算法
 * ============================================================
 *
 * 因为 dp[i] 只依赖 dp[i - 1]，
 * 所以不需要保存整个 dp 数组。
 *
 * 使用 cur：
 * 表示“以当前元素结尾的最大连续子数组和”。
 * cur = max(cur + nums[i], nums[i])
 *
 * 使用 ans：
 * 记录遍历过程中出现过的最大值。
 * ans = max(ans, cur)
 *
 * 如果前面的连续和能够增加当前结果，就继续接上；
 * 如果前面的连续和只会拖累当前结果，就从当前位置重新开始。

 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 *
 * ============================================================
 * 易错点
 * ============================================================
 *
 * 1. dp[0] 必须初始化为 nums[0]。
 *
 * 2. 最终不能直接返回 dp[n - 1]，
 *    因为最大子数组可能在数组中间就已经结束。
 *
 * 3. ans 应该初始化为 nums[0]，
 *    不能初始化为 0，
 *    因为数组可能全部都是负数。
 *
 * 4. dp[i] 的关键定义是：
 *    “必须以 nums[i] 结尾”。
 */

#include <vector>
#include <algorithm>

using namespace std;


// 解法一：DP 数组
class Solution53_DP {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n);

        dp[0] = nums[0];
        int ans = dp[0];

        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};


// 解法二：O(1) 空间优化
class Solution53_Optimized {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            cur = max(cur + nums[i], nums[i]);
            ans = max(ans, cur);
        }
        
        return ans;
    }
};
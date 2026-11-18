/*
 * LeetCode 213. 打家劫舍 II（House Robber II）
 *
 * 【算法】动态规划 / 环形数组拆成两个线性区间
 * 【题意】房屋首尾相邻，不能同时偷相邻的房屋；求能偷到的最大金额。
 *
 * 【核心思路】
 * 因为首尾两间不能同时选择，合法解一定满足“至少排除首或尾之一”。
 * 因此分两种情况，分别运行 LC0198 的线性打家劫舍 DP：
 *   情况 A：考虑区间 [0, n-2]（排除末尾房屋）
 *   情况 B：考虑区间 [1, n-1]（排除开头房屋）
 * 最终答案 = max(情况 A, 情况 B)。
 *
 * 【线性区间状态】
 * robRange(nums,left,right) 内，dp[i] 表示在 [left,i] 范围内能偷到的最大金额。
 * dp[left]   = nums[left]；
 * dp[left+1] = max(nums[left],nums[left+1])；
 * dp[i]      = max(dp[i-1], dp[i-2] + nums[i])：不偷第 i 间 / 偷第 i 间。
 *
 * 【易错点】
 * 1. 主函数 n==1 要特判，否则会传入非法区间 [0,-1]。
 * 2. 辅助函数 left==right 需要直接返回 nums[left]。
 * 3. 调用 robRange 时别漏传 nums 参数。
 * 4. 辅助函数返回 dp[right]，而非固定的 dp[n-1]。
 *
 * 【复杂度】两次线性 DP，总时间 O(n)，辅助空间 O(n)。
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int robRange(vector<int>& nums, int left, int right) {
        int n = nums.size();
        if (left == right) {
            return nums[left];
        }

        vector<int> dp(n, 0);
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left], nums[left + 1]);

        for (int i = left + 2; i <= right; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[right];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        int ans1 = robRange(nums, 0, n - 2);
        int ans2 = robRange(nums, 1, n - 1);
        return max(ans1, ans2);
    }
};

/*
 * LeetCode 198. House Robber
 *
 * Core:
 * dp[i] 表示考虑 0~i 号房屋时能偷到的最大金额。
 *
 * State Transition:
 * 偷 i   : dp[i-2] + nums[i]
 * 不偷 i : dp[i-1]
 *
 * dp[i] = max(dp[i-2] + nums[i], dp[i-1])
 *
 * Complexity:
 * Time O(n)
 * Space O(n)
 *
 * 易错点：
 * n 个元素的合法下标是 0 ~ n-1。
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution198 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        } // 只有一间房子，直接偷

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(
                dp[i - 2] + nums[i],
                dp[i - 1]
            );
        }

        return dp[n - 1];
    }
};
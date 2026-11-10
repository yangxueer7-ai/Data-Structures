/*
 * LC0643. 子数组最大平均数 I (Maximum Average Subarray I)
 *
 * 思路：固定长度滑动窗口
 * 1. 由于每个合法子数组的长度都为 k，最大平均值等价于最大窗口和除以 k。
 * 2. 右指针加入 nums[right]，窗口长度超过 k 时，减去 nums[left] 并右移 left。
 * 3. 当窗口长度恰好为 k 时，用当前窗口和更新 maxSum；不能漏掉第一个完整窗口。
 * 4. 最终转换为 double 后再除以 k，避免整数除法截断。
 *
 * 易错点：
 * - 数组可能全是负数，maxSum 应初始化为 INT_MIN（或第一个合法窗口和）。
 * - 收缩窗口与更新答案应独立处理，不能只在收缩时更新。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = INT_MIN;
        int n = nums.size();
        int left = 0;
        int curSum = 0;

        for (int right = 0; right < n; right++) {
            curSum += nums[right];
            if (right - left + 1 > k) {
                curSum -= nums[left];
                left++;
            }

            if (right - left + 1 == k) {
                maxSum = max(curSum, maxSum);
            }
        }

        return (double)maxSum / k;
    }
};

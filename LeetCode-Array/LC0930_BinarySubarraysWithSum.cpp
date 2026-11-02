/*
 * LeetCode 930. Binary Subarrays With Sum（和相同的二元子数组）
 *
 * 解法：双滑动窗口 / 至多 K 的子数组数量
 * 核心转化：恰好等于 goal = 至多 goal - 至多 (goal - 1)
 *
 * 由于 nums 中只有 0 和 1（均为非负数），右端点右移时窗口和不会减小，
 * 左端点右移时窗口和不会增加，因此可以用滑动窗口求“和 <= limit”
 * 的连续非空子数组个数。
 *
 * 对于固定的右端点 right：
 *   1. 加入 nums[right]，扩展当前窗口；
 *   2. 若 sum > limit，则持续移除 nums[left] 并右移 left；
 *   3. 此时所有以 right 为结尾、起点在 [left, right] 内的子数组
 *      都满足 sum <= limit，数量恰好为 right - left + 1。
 *
 * 特别注意：goal 可能为 0。计算 atMost(goal - 1) 时，
 * limit 可能是 -1；由于所有元素非负，不存在和 <= -1 的非空子数组，
 * 必须直接返回 0，否则收缩窗口可能越界。
 *
 * 时间复杂度：O(n)，两次线性滑动窗口；
 * 额外空间复杂度：O(1)。
 */

#include <vector>
using namespace std;

class Solution {
private:
    int atMost(const vector<int>& nums, int limit) {
        if (limit < 0) {
            return 0;
        }

        int left = 0;
        int sum = 0;
        int count = 0;

        for (int right = 0; right < static_cast<int>(nums.size()); right++) {
            sum += nums[right];

            // 使当前窗口的和重新满足 <= limit。
            while (sum > limit) {
                sum -= nums[left];
                left++;
            }

            // 以 right 结尾的合法子数组有 right - left + 1 个。
            count += right - left + 1;
        }

        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

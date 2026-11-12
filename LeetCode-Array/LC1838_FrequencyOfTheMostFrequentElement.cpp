/*
 * LeetCode 1838. 最高频元素的频数
 * 英文题名：Frequency of the Most Frequent Element
 *
 * 算法：排序 + 可变长度滑动窗口（操作成本约束）
 *
 * 核心思路：
 * 1. 先将 nums 升序排序。因为只能增加元素的值，所以将当前窗口内
 *    所有元素变为 nums[right]，所需操作次数最少。
 * 2. 使用 windowSum 维护 [left, right] 区间的元素和。
 *    将整个窗口变为 nums[right] 的操作次数为：
 *       cost = 1LL * nums[right] * (right - left + 1) - windowSum
 * 3. 若 cost > k，则不断移除左端元素，直到窗口的操作次数不超过 k。
 * 4. 每次窗口合法后，用 right - left + 1 更新最大频数。
 *
 * 易错点：
 * - 必须先排序，才能以 nums[right] 作为窗口内的统一目标值。
 * - 窗口收缩时，windowSum 必须同步减去 nums[left]。
 * - cost == k 也是合法窗口，故收缩条件为 cost > k，而非 >= k。
 * - 即使 cost 与 windowSum 是 long long，两个 int 相乘时仍可能溢出；
 *   要在乘法前使用 1LL 将计算提升到 long long。
 *
 * 时间复杂度：O(n log n)，主要来自排序；滑动窗口扫描 O(n)。
 * 空间复杂度：滑动窗口 O(1)；std::sort 的递归栈一般为 O(log n)。
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        long long windowSum = 0;
        int left = 0;
        int maxAns = 0;
        long long cost = 0;

        sort(nums.begin(), nums.end());

        for (int right = 0; right < n; right++) {
            windowSum += nums[right];
            cost = 1LL * nums[right] * (right - left + 1) - windowSum;

            while (cost > k) {
                windowSum -= nums[left];
                left++;
                cost = 1LL * nums[right] * (right - left + 1) - windowSum;
            }

            maxAns = max(maxAns, right - left + 1);
        }

        return maxAns;
    }
};

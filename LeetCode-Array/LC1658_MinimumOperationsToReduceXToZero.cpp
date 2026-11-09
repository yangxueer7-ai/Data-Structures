/*
 * LC1658. 将 x 减到 0 的最小操作数
 *
 * 思路：逆向思考 + 可变长度滑动窗口
 * 1. 每次只能从左右两端删除元素，因此剩余部分一定是连续子数组。
 * 
 * 2. 删除元素的和恰好为 x，等价于寻找和为 total - x 的最长连续子数组。
 * 
 * 3. 数组元素均为正整数，窗口和超过 target 时不断收缩左端；
 *    窗口和等于 target 时更新最长保留长度 ans。
 * 
 * 4. 最少删除次数 = n - 最长保留长度。
 *
 * 边界：
 * - total < x：无法删除出总和为 x 的元素，返回 -1。
 * - total == x：需要删除整个数组，返回 n。
 * - 找不到和为 target 的连续子数组：返回 -1。
 *
 * 易错点：
 * - target = total - x，而不是 x - total。
 * - ans 记录保留子数组的最大长度，最终返回 n - ans。
 * - 用 ans = -1 区分“还未找到合法窗口”。
 *
 * 时间复杂度：O(n)，空间复杂度：O(1)。
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;

        for (int y : nums) {
            total += y;
        }

        if (total < x) {
            return -1;
        }

        if (total == x) {
            return n;
        }

        int left = 0;
        int ans = -1;
        int sum = 0;
        int target = total - x;

        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            if (sum == target) {
                ans = max(ans, right - left + 1);
            }
        }

        return ans == -1 ? -1 : n - ans;
    }
};

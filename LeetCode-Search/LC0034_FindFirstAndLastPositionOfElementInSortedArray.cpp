/*
 * LeetCode 34. 在排序数组中查找元素的第一个和最后一个位置
 * 难度：Medium
 * 专题：Binary Search / Lower Bound / Upper Bound
 *
 * 核心思路：左闭右开二分查找，两次寻找左右边界
 *
 * 一、第一次二分：寻找左边界 lower_bound
 * 目标：找到第一个 >= target 的位置。
 * 初始化：
 * left = 0;
 * right = n;
 * 结束时 left == right，即第一个 >= target 的位置。
 * 如果 target 存在，则 left 是它第一次出现的下标。
 *
 * 二、第二次二分：寻找右边界 upper_bound
 * 目标：找到第一个 > target 的位置。
 * 从已找到的左边界开始，重新设置 right = n。
 *
 * 结束时：
 * left 是第一个 > target 的位置。
 * 因此最后一个 target 的下标为 left - 1。
 *
 * 三、最终答案
 *
 * ans[0] = lower_bound 对应的下标;
 * ans[1] = upper_bound 对应的下标 - 1;
 *
 * 如果 target 不存在，返回 {-1, -1}。
 *
 * 四、本次易错点
 * 1. 一开始使用普通二分找到某个 target，
 *    再尝试通过 mid++ 寻找右边界。
 *    问题：
 *    - 线性扫描最坏需要 O(n) 时间。
 *    - 找到 target 后没有更新 left/right，可能死循环。
 *    - mid++ 可能造成数组越界。
 *
 * 2. 判断 target 是否存在时，条件顺序写反：
 *
 *    错误：
 *    if (nums[left] != target || left == n)
 *
 *    原因：
 *    C++ 的 || 具有短路求值特性。
 *    如果 left == n 成立，就不会访问 nums[left]。
 *    必须先判断下标是否合法，再访问数组元素。
 
 *
 * 五、C++ STL 拓展
 *
 * lower_bound(nums.begin(), nums.end(), target)
 *     返回第一个 >= target 的迭代器。
 *
 * upper_bound(nums.begin(), nums.end(), target)
 *     返回第一个 > target 的迭代器。
 *
 * 通过减去 nums.begin() 可以得到数组下标。
 *
 * 两个迭代器的距离等于 target 的出现次数。
 * 前提：数组已按升序排列。
 *
 * 六、复杂度分析
 *
 * 时间复杂度：O(log n)
 * 两次二分查找，每次都将搜索范围缩小约一半。
 * 额外空间复杂度：O(1)
 * 只使用常数个辅助变量，不计算返回数组。
 *
 * 七、相关题目
 *
 * LC704：普通二分查找。
 * LC35：搜索插入位置，本质是 lower_bound。
 * LC34：同时使用 lower_bound 和 upper_bound。
 * LC300：后续复盘贪心 + 二分查找优化 LIS。
 *
 */
#include <vector>

using namespace std;


class Solution34 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n;
        vector<int> ans(2, -1);

        while (left < right) {
            int mid = left + (right - left) / 2;

            // 找到第一个≥target的位置
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        if (left == n || nums[left] != target) {
            return ans;
        }

        ans[0] = left;

        // 找到第一个>target的位置

        right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        ans[1] = left - 1;

        return ans;
    }
};
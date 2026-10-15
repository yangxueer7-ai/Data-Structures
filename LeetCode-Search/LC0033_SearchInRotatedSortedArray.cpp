/*
 * LeetCode 33. 搜索旋转排序数组 (Search in Rotated Sorted Array)
 * 难度：Medium
 * 算法：二分查找 / 旋转数组
 *
 * 【题意】
 * 给定一个经过旋转的升序数组（元素互不相同）和目标值 target，
 * 返回 target 的下标；若不存在则返回 -1。
 *
 * 【核心思路】
 * 旋转数组虽然整体不一定有序，但每次二分至少有一半有序。
 * 先判断哪一半有序，再判断 target 是否位于该有序区间，
 * 从而排除不可能包含 target 的一半。
 *
 * 【二分过程】
 * 1. 使用左闭右闭区间 [left, right]，循环条件 left <= right。
 * 2. 如果 nums[mid] == target，直接返回 mid。
 * 3. 如果 nums[left] <= nums[mid]，说明左半边有序：
 *    - nums[left] <= target < nums[mid]：right = mid - 1
 *    - 否则：left = mid + 1
 * 4. 否则右半边有序：
 *    - nums[mid] < target <= nums[right]：left = mid + 1
 *    - 否则：right = mid - 1
 * 5. 搜索结束仍未找到，返回 -1。
 *
 * 【易错点】
 * 1. 不能直接套普通有序数组的 lower_bound 模板。
 * 2. 判断哪半边有序，不代表一定要搜索那一半。
 * 3. nums[mid] 已经检查过，因此更新边界时可以排除 mid。
 * 4. 注意区间端点的 <= 和 <，避免遗漏 target。
 * 5. 本题元素互不相同；存在大量重复元素时不能直接套用此判断。
 *
 * 【复杂度】
 * 时间复杂度：O(log n)
 * 空间复杂度：O(1)
 *
 * 旋转数组二分：先找有序半区，再利用 target 的范围排除一半。
 */

#include <vector>

using namespace std;

class Solution33 {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // 左半边有序
            if (nums[mid] >= nums[left]) {
                // target在这个范围中，更新right
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }

            // 右半边有序
            else {
                //target在这个范围中，更新Left
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
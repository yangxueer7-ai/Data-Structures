/*
 * LeetCode 0540 - 有序数组中的单一元素
 * Single Element in a Sorted Array
 *
 * 算法：二分查找 + 下标奇偶性
 * 难度：Medium
 *
 * 【题目描述】
 * 给定一个有序数组，除某一个元素只出现一次外，
 * 其余元素都恰好出现两次。
 * 要求找到这个单独出现的元素。
 *
 * 时间复杂度要求：O(log n)
 * 空间复杂度要求：O(1)
 *
 * 【核心思路】
 * 由于数组有序，重复元素必然相邻。
 *
 * 在单独元素出现之前：
 * 重复元素按照 (偶数下标, 奇数下标) 配对。
 *
 * 在单独元素出现之后：
 * 重复元素按照 (奇数下标, 偶数下标) 配对。
 *
 * 因此，可以通过检查配对规律是否被破坏，
 * 使用二分查找确定单独元素的位置。
 *
 * 【算法流程】
 * 1. 初始化 left = 0，right = n - 1。
 *    使用左闭右闭区间 [left, right]。
 *
 * 2. 当 left < right 时，计算 mid。
 *
 * 3. 如果 mid 是奇数，则执行 mid--，
 *    统一将 mid 调整到偶数下标。
 *
 * 4. 判断 nums[mid] 和 nums[mid + 1]：
 *
 *    (1) 如果相等：
 *        说明当前两个元素正常配对。
 *        单独元素一定在它们右侧。
 *        left = mid + 2;
 *
 *    (2) 如果不相等：
 *        说明配对规律已经被破坏。
 *        单独元素在 mid 或其左侧。
 *        right = mid;
 *
 * 5. 循环结束时 left == right，
 *    返回 nums[left]。
 *
 * 【复杂度分析】
 * 时间复杂度：O(log n)
 * 每次二分都缩小搜索区间。
 *
 * 空间复杂度：O(1)
 * 只使用 left、right、mid 等常数个变量。
 
 * 【易错点】
 * 1. mid 必须在 while 循环内部重新计算，
 *    否则边界变化后 mid 不更新，可能导致 TLE。
 *
 * 2. mid 必须调整成偶数下标，
 *    才能统一判断 nums[mid] 和 nums[mid+1]。
 *
 * 3. 如果配对成功，left = mid + 2，
 *    因为当前两个元素都可以排除。
 *
 * 4. 如果配对失败，right = mid，
 *    因为 mid 本身可能就是单独元素。
 *
 * 5. 本实现使用左闭右闭区间。
 *    题目保证数组长度为奇数，
 *    在上述区间更新规则下 mid+1 不会越界。
 *
 * 6. 最终返回 nums[left]，而不是 nums[mid]。

 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;


        while (left < right) {
            //偶-奇规律 如果取的mid不是偶数，转化一下
            int mid = left + (right - left) / 2;

            if (mid % 2 == 1) {
                mid--;
            }
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            }
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};
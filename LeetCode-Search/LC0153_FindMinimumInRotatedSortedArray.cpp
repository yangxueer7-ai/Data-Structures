
/*
 * LeetCode 153. 寻找旋转排序数组中的最小值
 * 难度：Medium
 * 专题：Binary Search / Rotated Sorted Array
 *
 * 核心思路：二分查找 + 利用旋转数组的局部有序性
 *
 * 一、题目特点
 *
 * 1. 原数组严格升序，经过若干次旋转。
 * 2. 数组中的元素互不相同。
 * 3. 旋转后可能形成两段分别升序的区间。
 * 4. 目标是寻找最小元素的值，而不是下标。
 *
 * 例如：
 * nums = [4,5,6,7,0,1,2]
 * 最小值为 0。
 *
 * 二、核心思路
 * 使用 left、right 维护可能包含最小值的闭区间。
 
 * 比较 nums[mid] 和 nums[right]：

 * 情况① nums[mid] > nums[right]
 *
 * 说明最小值一定在 mid 右侧。
 * 因为 nums[mid] 比右端点大，
 * 旋转产生的下降位置必然位于右半部分。
 * 更新：
 * left = mid + 1;
 *
 * 情况② nums[mid] < nums[right]
 *
 * 说明从 mid 到 right 的区间严格升序，
 * 最小值不可能在 mid 右侧。
 * 但 nums[mid] 自己可能就是最小值，
 * 因此不能排除 mid。
 *
 * 更新：
 * right = mid;
 *
 * 三、循环条件和返回值

 * 当 left == right 时，
 * 区间中只剩下一个候选元素，
 * 该元素就是最小值。
 *
 * return nums[left];
 *
 * 四、复杂度分析
 *
 * 时间复杂度：O(log n)
 * 每轮排除约一半的候选元素。
 *
 * 空间复杂度：O(1)
 * 仅使用 left、right、mid 等常数变量。
 *
 * 中点大于右端点，最小值在右边；
 * 中点小于右端点，最小值在中点或左边。
 */


#include <vector>

using namespace std;

class Solution153 {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};
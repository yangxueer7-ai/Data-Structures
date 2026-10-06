/*
 * LeetCode 977. Squares of a Sorted Array
 * 题目：有序数组的平方
 *
 * 核心思路：
 * 双指针。
 *
 * 原数组虽然是非递减排列，
 * 但平方后最大的值不一定出现在右边，
 * 因为左边的负数绝对值可能更大。
 *
 * 因此使用两个指针：
 *
 * left：
 * 指向数组最左端。
 *
 * right：
 * 指向数组最右端。
 *
 * pose：
 * 指向结果数组当前要写入的位置。
 * 因为每次比较得到的是当前最大的平方值，
 * 所以从结果数组末尾开始往前填写。
 *
 * 每一轮：
 *
 * leftSquare  = nums[left] * nums[left]
 * rightSquare = nums[right] * nums[right]
 *
 * 如果 leftSquare 更大：
 *     result[pose] = leftSquare
 *     left++
 *
 * 否则：
 *     result[pose] = rightSquare
 *     right--
 *
 * 然后pose--
 *
 * 关键理解：
 * 1. 平方后的最大值一定来自当前数组的左右两端之一。
 * 2. ★每次只移动被选中的那一侧指针。
 * 3. 结果数组要从后往前填，因为每次先确定的是较大的值。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include<vector>

using namespace std;

class Solution977 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return nums;
        }

        int left = 0;
        int right = n - 1;

        vector<int> result(n);

        for (int pos = n - 1; pos >= 0; pos--) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                result[pos] = leftSquare;
                left++;
            }
            else {
                result[pos] = rightSquare;
                right--;
            }
        }

        return result;
    }
};

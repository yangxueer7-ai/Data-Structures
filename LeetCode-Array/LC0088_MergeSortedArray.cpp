/*
 * LeetCode 88. Merge Sorted Array
 * 题目：合并两个有序数组
 *
 * 核心思路：
 * 三指针 + 从后往前写。
 *
 * nums1 的末尾已经预留了 n 个位置，
 * 所以不需要额外开新数组。
 *
 * 三个指针：
 * p1：
 * 指向 nums1 有效元素的最后一个位置。
 *
 * p2：
 * 指向 nums2 最后一个位置。
 *
 * write：
 * 指向 nums1 当前应该写入的位置。
 *
 * 初始化：
 *
 * p1 = m - 1
 * p2 = n - 1
 * write = m + n - 1
 *
 * 每一轮：
 *
 * 比较 nums1[p1] 和 nums2[p2]。
 *
 * 谁更大，就把谁放到 nums1[write]，
 * 然后对应指针左移。
 *
 * 为什么要从后往前写？
 * 因为 nums1 后面有预留空间。
 * 从后往前填不会覆盖 nums1 前面还没有参与比较的有效元素。
 *
 * 为什么 nums1[p1] 也要重新写入？
 * 因为 nums1[p1] 虽然本来就在 nums1 中，
 * 但它不一定已经位于合并后的最终正确位置。
 *
 * 例如：
 *
 * nums1 = [1,3,5,0,0,0]
 * nums2 = [2,4,6]
 * 数字 5 原本在下标 2，
 * 但合并后应该移动到更靠后的位置。
 *
 * 最后的 while(p2 >= 0)：
 *
 * 如果 nums1 的有效元素先用完，
 * nums2 可能还有剩余元素，
 * 需要继续把 nums2 剩余部分写入 nums1。
 * 不需要额外处理 nums1 剩余元素：
 *
 * 如果 nums2 先用完，
 * nums1 前面剩下的元素本来就在正确位置，
 * 不需要再次移动。
 *
 * 易错点：
 * 每次只移动被选中的那个读指针。
 * 最后只需要补 nums2 的剩余元素。
 *
 * 时间复杂度：O(m + n)
 * 空间复杂度：O(1)
 */

#include <vector>

using namespace std;

class Solution88 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int write = m + n - 1;

        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[write] = nums1[p1];
                p1--;
            }
            else {
                nums1[write] = nums2[p2];
                p2--;
            }

            write--;
        }

        // nums1 用完了，但 nums2 还有剩余
        while (p2 >= 0) {
            nums1[write] = nums2[p2];
            p2--;
            write--;
        }
    }
};
#include <vector>
using namespace std;

/*
 * 算法名称：希尔排序（Shell Sort，缩小增量排序）
 *
 * 【基本思想】
 * 1. 从 gap = n / 2 开始，将下标相差 gap 的元素视作同一组。
 * 2. 对每组进行“步长为 gap 的插入排序”，让元素可以跨较大距离移动。
 * 3. gap 每轮减半，直到 gap = 1，对整个数组完成最后一轮插入排序。
 *
 * 【408 考点】
 * - 原地排序：是；辅助空间 O(1)。
 * - 稳定性：不稳定。不同组之间的移动可能改变相等元素的相对顺序。
 * - 时间复杂度与增量序列有关。对于这里的 gap 每次减半的实现：
 *   已有序情况下约 O(n log n)，最坏情况 O(n^2)；不宜一概而论平均复杂度。
 * - gap = 1 不仅“类似”直接插入排序，而是实际执行一次普通插入排序；
 *   它保证跨组元素最终也能按大小排好序。
 *
 * 【易错点】
 * - 插入排序的下标位移从 1 改为 gap：j -= gap，nums[j + gap]。
 * - 每轮的 i 从 gap 开始，前 gap 个元素分别是各组的第一个元素。
 * - 必须保留 gap = 1 这一轮，不可在 gap = 2 后停止。
 */


void shellSort(vector<int>& nums) {
    int n = static_cast<int>(nums.size());

    // gap每次缩小一半，初始是长度的一半，到1结束🔚
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int key = nums[i];
            int j = i - gap;

            while (j >= 0 && nums[j] > key) {
                nums[j + gap] = nums[j];
                j -= gap;
            }

            nums[j + gap] = key;
        }
    }
}

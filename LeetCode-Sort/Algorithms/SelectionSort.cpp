#include <vector>
using namespace std;

/*
 * 算法名称：简单选择排序（Selection Sort）
 * 算法类别：选择排序 / 408 数据结构
 * 推荐归档：LeetCode-Sort/Algorithms/SelectionSort.cpp
 *
 * 【核心思想】
 * 1. 将数组划分为左侧有序区和右侧无序区。
 * 2. 第 i 轮在 [i, n-1] 内寻找最小元素的下标 minIndex。
 * 3. 将该最小元素与 nums[i] 交换，扩大左侧有序区。
 * 4. 进行 n-1 轮即可完成排序。
 *
 * 【重要变量】
 * i        ：当前无序区起点，也是本轮最小值要放的位置。
 * j        ：扫描剩余无序区的下标。
 * minIndex ：已扫描元素中最小值所在的下标。
 *
 * 【复杂度】
 * 最好 / 平均 / 最坏时间：O(n^2)，有序数组也要完整比较。
 * 辅助空间：O(1)，原地排序。
 * 交换次数：至多 n-1 次（跳过 minIndex == i 的自交换）。
 *
 * 【408 重要性质】
 * 不稳定。例如 [2a, 2b, 1] 第一次交换后成为 [1, 2b, 2a]，
 * 两个相同关键字元素的相对顺序发生变化。
 *
 * 【易错点】
 * 1. 比较 nums[j] 与 nums[minIndex]，不能一直比较 nums[i]。
 * 2. 内层 j 从 i+1 开始；外层 i < n-1。
 * 3. minIndex 是下标，不是最小值本身。
 */


void selectionSort(vector<int>& nums) {
    int n = static_cast<int>(nums.size());

    // 外层：确定无序区的第一个位置 i
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // 内层：从无序区寻找最小元素
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }

        // 只在需要时交换
        if (minIndex != i) {
            int temp = nums[i];
            nums[i] = nums[minIndex];
            nums[minIndex] = temp;
        }
    }
}

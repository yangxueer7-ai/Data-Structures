#include <vector>
using namespace std;

/*
 * 算法名称：快速排序（Quick Sort）
 * 算法分类：交换排序 / 分治算法
 * 归档路径：LeetCode-Sort/Algorithms/QuickSort.cpp
 *
 * 【核心思想】
 * 1. 选取当前区间的第一个元素作为枢轴 pivot。
 * 2. 用左右双指针进行一次 partition（挖坑法）：
 *    - 先从右向左寻找严格小于 pivot 的元素，填入左侧的坑；
 *    - 再从左向右寻找严格大于 pivot 的元素，填入右侧的坑；
 *    - 两指针相遇后，把 pivot 放回最后的坑，并返回该下标 p。
 * 3. 枢轴 p 已经位于最终位置，再递归排序 [left, p-1] 和 [p+1, right]。
 *
 * 【重要区别】
 * - partition 结束后，只能保证 pivot 左侧元素 <= pivot，右侧元素 >= pivot；
 *   左右区间的内部尚未必有序。
 * - 归并排序：先递归，再 merge；快速排序：先 partition，再递归。
 *
 * 【时间复杂度】
 * 最好：O(n log n)；平均：O(n log n)；最坏：O(n^2)。
 * 使用首元素作为 pivot 时，已经升序/降序的数组可能出现极不均衡划分。
 *
 * 【空间复杂度】
 * 划分本身 O(1)；递归栈平均 O(log n)，最坏 O(n)。
 *
 * 【408 性质】
 * 不稳定；原地排序（除递归栈外，无 O(n) 辅助数组）。
 *
 * 【易错点】
 * 1. 首元素为 pivot 的挖坑法要先从右侧 j 开始扫描。
 * 2. 填坑是 nums[i] = nums[j] 和 nums[j] = nums[i]，不能固定写 nums[left]。
 * 3. i/j 扫描条件要分别使用 nums[j] >= pivot / nums[i] <= pivot。
 * 4. partition() 返回枢轴位置 p，而不是枢轴数值。
 * 5. 递归区间需排除 p，终止条件为 left >= right。
 */

 // 将 nums[left..right] 按首元素枢轴划分，返回枢轴的最终下标。
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int i = left;
    int j = right;

    while (i < j) {
        // 右边找严格小于 pivot 的元素，填入左侧的坑
        while (i < j && nums[j] >= pivot) {
            j--;
        }
        nums[i] = nums[j];

        // 左边找严格大于 pivot 的元素，填入右侧的坑
        while (i < j && nums[i] <= pivot) {
            i++;
        }
        nums[j] = nums[i];
    }

    // i == j：枢轴回填到最后的坑中
    nums[i] = pivot;
    return i;
}

// 左闭右闭区间 [left, right] 内进行快速排序。
void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }

    int p = partition(nums, left, right);
    quickSort(nums, left, p - 1);
    quickSort(nums, p + 1, right);
}

// 排序整个数组的便捷入口
void quickSort(vector<int>& nums) {
    if (nums.empty()) {
        return;
    }
    quickSort(nums, 0, static_cast<int>(nums.size()) - 1);
}

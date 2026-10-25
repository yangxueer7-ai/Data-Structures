
#include <vector>
using namespace std;

/*
 * 算法名称：冒泡排序（Bubble Sort）
 * 算法类型：交换排序
 *
 * 【核心思想】
 * 1. 每轮从左向右比较相邻元素。
 * 2. 如果前一个元素大于后一个元素，则交换。
 * 3. 每轮结束，未排序区的最大元素到达最终位置。
 * 4. 右侧有序区逐渐扩大，左侧无序区逐渐缩小。
 *
 * 【优化】
 * 使用 swapped 标志位：
 * - 每轮开始初始化为 false
 * - 发生交换时设置为 true
 * - 若整轮没有交换，说明数组已有序，提前退出
 *
 * 【复杂度】
 * 最好时间：O(n)       已有序，仅比较一轮
 * 平均时间：O(n²)
 * 最坏时间：O(n²)      逆序等情况
 * 空间复杂度：O(1)
 *
 * 【408 性质】
 * 稳定性：稳定（相等元素不交换）
 * 原地排序：是
 */

void bubbleSort(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        // 右侧为有序区，左侧为无序区
        for (int j = 0; j < n - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;

                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

/*
 * Straight Insertion Sort
 * 直接插入排序
 *
 * 算法类别：内部排序 / 插入排序
 *
 * 基本思想：
 * 将数组划分为有序区和无序区。
 * 每次从无序区取出一个元素，插入有序区的正确位置。
 *
 * 算法过程：
 * 1. 默认 nums[0] 已经有序。
 * 2. 从 i=1 开始，依次取出 nums[i] 作为 key。
 * 3. 令 j=i-1，从有序区末尾向左比较。
 * 4. 如果 nums[j]>key，将 nums[j] 右移一位。
 * 5. 重复比较，直到找到插入位置。
 * 6. 将 key 放入 nums[j+1]。
 *
 * 408 复杂度：
 * 最好时间复杂度：O(n)      原数组已经有序
 * 平均时间复杂度：O(n^2)
 * 最坏时间复杂度：O(n^2)    原数组完全逆序
 * 辅助空间复杂度：O(1)
 *
 * 稳定性：稳定
 * 排序方式：原地排序
 *
 * 为什么稳定？
 * 因为只有 nums[j]>key 时才向右移动。
 * 当两个元素相等时，不会改变它们的相对顺序。
 *
 * 易错点：
 * 1. i 从 1 开始，不是 0。
 * 2. key 必须提前保存。
 * 3. j>=0 防止数组越界。
 * 4. 使用 nums[j]>key 保证稳定性。
 * 5. j-- 后，最终插入位置为 j+1。
 */

#include <vector>
using namespace std;

void insertionSort(vector<int>& nums) {
    int n = nums.size();

    for (int i = 1; i < n; i++) {
        int key = nums[i];
        int j = i - 1;

        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = key;
    }
}
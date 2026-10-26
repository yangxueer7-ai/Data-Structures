#include <vector>
using namespace std;

/*
 * 算法名称：折半插入排序（Binary Insertion Sort）
 * 算法类别：插入排序 / 二分查找 / 408 数据结构
 *
 * 【核心思想】
 * 1. 将 nums[0..i-1] 视为已排序区，取出 nums[i] 作为 key。
 * 2. 在已排序区 [0, i) 中用二分查找定位插入位置：
 *    找到第一个严格大于 key 的元素下标 left。
 * 3. 将区间 [left, i-1] 内的元素从右向左依次右移一格。
 * 4. 把 key 放到 nums[left]，使左侧有序区扩大一位。
 *
 * 【稳定性】
 * 在二分查找中使用 nums[mid] <= key 时 left = mid + 1，
 * 让新 key 插到原有相等元素的后面，不改变相等元素的相对顺序。
 * 因此该实现是稳定排序。
 *
 * 【复杂度】
 * 最好时间复杂度：O(n log n)，即使原数组已有序，仍需逐轮二分查找。
 * 平均时间复杂度：O(n^2)，元素移动仍可能很多。
 * 最坏时间复杂度：O(n^2)，例如原数组逆序时，大量元素要右移。
 * 辅助空间复杂度：O(1)，只使用常数个变量。
 * 原地排序：是。
 *
 * 【易错点】
 * 1. 搜索区间为左闭右开 [0, i)，初始 right = i。
 * 2. 使用 <= 而不是 <，找到第一个严格大于 key 的位置，保持稳定。
 * 3. 右移范围必须包括 left：for (j = i - 1; j >= left; --j)。
 * 4. 移动必须从右向左，否则可能覆盖还未搬移的元素。
 * 5. 折半只减少比较次数，不改变最坏情况下 O(n^2) 的移动量。
 */


void binaryInsertionSort(vector<int>& nums) {
    int n = static_cast<int>(nums.size());

    for (int i = 1; i < n; i++) {
        int key = nums[i];

        // 1. 在左侧已排序区 [0, i) 二分寻找第一个 > key 的位置
        int left = 0;
        int right = i;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= key) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        // 2. 从右往左移动 [left, i-1] 的元素，为 key 腾出位置
        for (int j = i - 1; j >= left; j--) {
            nums[j + 1] = nums[j];
        }

        // 3. 将 key 插入找到的位置
        nums[left] = key;
    }
}

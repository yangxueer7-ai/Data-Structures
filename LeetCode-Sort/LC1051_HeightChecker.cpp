/*
 * LeetCode 1051. Height Checker
 * 身高检查器
 *
 * 算法：直接插入排序 / 数组比较
 *
 * 核心思路：
 * 1. 复制原数组 heights，得到 expected。
 * 2. 使用手写的直接插入排序，将 expected 升序排列。
 * 3. 保留原数组不变，逐个比较 heights[i] 和 expected[i]。
 * 4. 如果相同下标处的元素不同，ans++。
 * 5. 返回所有位置不匹配的数量。
 *
 * 直接插入排序：
 * - 默认第一个元素已经有序。
 * - 从下标 1 开始，取出当前待插入元素 key。
 * - 从有序区末尾向左比较。
 * - 将所有大于 key 的元素向右移动。
 * - 最后把 key 放到 nums[j+1] 的位置。
 *
 * 时间复杂度：O(n^2)，最坏情况
 * 空间复杂度：O(n)，复制 expected 数组
 *
 * 易错点：
 * 1. 必须保留原数组，不能直接排序 heights。
 * 2. 比较的是相同下标的元素，而非所有元素对。
 * 3. 直接插入排序的外层循环从 i=1 开始。
 * 4. 必须提前保存 key，防止右移时覆盖原值。
 * 5. while 循环结束后，应插入 nums[j+1]。
 * 6. 插入排序本身是 O(1) 辅助空间，
 *    但本题还需要 O(n) 空间保存 expected。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        int ans = 0;

        insertionSort(expected);

        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]) {
                ans++;
            }
        }

        return ans;
    }

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
};
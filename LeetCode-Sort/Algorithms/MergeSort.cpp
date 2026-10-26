#include <vector>
using namespace std;

/*
 * 算法名称：归并排序（Merge Sort）
 * 算法思想：分治 + 双指针合并
 *
 * 【核心思路】
 * 1. mergeSort 将区间 [left, right] 拆成左右两半。
 * 2. 递归排序 [left, mid] 和 [mid+1, right]。
 * 3. merge 把两个已有序区间合并，写回原数组对应位置。
 *
 * 【408 考点】
 * 最好 / 平均 / 最坏时间复杂度：O(n log n)
 * 辅助空间复杂度：O(n)（临时数组及递归调用栈）
 * 稳定性：稳定。两个元素相等时，优先取左区间的元素。
 * 原地排序：否（本实现使用额外的临时数组）。
 *
 * 【易错点】
 * - 左右两段均为闭区间：[left, mid] 和 [mid+1, right]。
 * - 递归边界是 left >= right；右半段必须从 mid+1 开始。
 * - temp 存储的是当前子区间，写回应使用 nums[left+k]。
 * - 范围 for 得到的是元素值，不是下标。
 */

void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp;
    int i = left;
    int j = mid + 1;

    // 比较左右两个有序区间，优先取较小值；
    // 相等时优先取左侧以保持稳定性
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        }
        else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    // 追加尚未处理完的左区间元素
    while (i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }

    // 追加尚未处理完的右区间元素
    while (j <= right) {
        temp.push_back(nums[j]);
        j++;
    }

    // 将临时结果写回原数组中 [left, right] 的对应位置
    for (int k = 0; k < static_cast<int>(temp.size()); k++) {
        nums[left + k] = temp[k];
    }
}

void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    // 递归排序左区间，右区间
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

// 对整个数组排序的便捷入口
void mergeSort(vector<int>& nums) {
    if (!nums.empty()) {
        mergeSort(nums, 0, static_cast<int>(nums.size()) - 1);
    }
}

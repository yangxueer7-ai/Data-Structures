#include <vector>
using namespace std;

/*
 * LeetCode 215. 数组中的第 K 个最大元素
 *
 * 方法：快速选择 Quickselect（首元素 pivot + 双指针挖坑法）
 *
 * 思路：
 * 1. 第 k 大相当于升序排列后下标为 n-k 的元素。
 * 2. partition 选当前区间第一个元素为 pivot，右指针先找小于 pivot 的元素填左坑，
 *    左指针再找大于 pivot 的元素填右坑，最终将 pivot 放回相遇位置。
 * 3. pivot 的最终下标 p 已确定；只需继续在包含 target 的一侧查找，
 *    不必像快速排序那样递归处理左右两侧。
 *
 * 时间复杂度：典型均衡划分时 O(n)，极端情况下 O(n^2)。
 * 空间复杂度：O(1)（采用迭代式 Quickselect）。
 *
 * 注意：此处刻意保留本人最初手写的固定首元素 pivot 版本，不加入随机化。
 * 该版本在 LeetCode 某些测试中曾超时（TLE），不能将其视为提交 AC 的版本。
 * 实际平台 AC 的版本使用随机 pivot；未来计划复盘三路划分，优化重复元素场景。
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        int target = n - k;  // 第 k 大对应的升序下标

        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int p = partition(nums, left, right);

            if (p == target) {
                return nums[p];
            }
            else if (target < p) {
                right = p - 1;  // partition 的下标 p，而不是区间中点 mid
            }
            else {
                left = p + 1;
            }
        }

        return -1;  // 根据题目保证的合法输入，不会走到这里
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];  
        int i = left;
        int j = right;

        while (i < j) {
            // 从右向左找小于 pivot 的元素，填左侧的坑
            while (i < j && nums[j] >= pivot) {
                --j;
            }
            nums[i] = nums[j];

            // 从左向右找大于 pivot 的元素，填右侧的坑
            while (i < j && nums[i] <= pivot) {
                ++i;
            }
            nums[j] = nums[i];
        }

        nums[i] = pivot;
        return i;  // 返回 pivot 的最终下标
    }
};

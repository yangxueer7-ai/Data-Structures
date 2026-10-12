/*
 * LeetCode 704. 二分查找
 * 难度：Easy
 * 专题：Binary Search / Array / Searching
 *
 * 核心思路：
 * 在有序数组中，每次比较 nums[mid] 和 target，
 * 排除一半不可能包含目标值的区间。
 *
 * 一、左闭右闭 [left, right]
 *
 * 初始化：
 * left = 0;
 * right = n - 1;
 *
 * 循环条件：while (left <= right)
 *
 * 1. nums[mid] == target：返回 mid。
 * 2. nums[mid] < target：left = mid + 1。
 * 3. nums[mid] > target：right = mid - 1。
 *
 * 因为 right 属于搜索区间，
 * 所以 left == right 时仍需检查最后一个元素。
 *
 * 二、左闭右开 [left, right)
 *
 * 初始化：
 * left = 0;
 * right = n;
 *
 * 循环条件：while (left < right)
 *
 * 1. nums[mid] == target：返回 mid。
 * 2. nums[mid] < target：left = mid + 1。
 * 3. nums[mid] > target：right = mid。
 *
 * 因为 right 不属于搜索区间，
 * 所以 right = mid 就已经排除了 mid。
 * 当 left == right 时，搜索区间为空。
 *
 * 三、重要语法
 *
 * int mid = left + (right - left) / 2;
 *
 * - 相比 (left + right) / 2，可以避免加法整数溢出。
 * - mid 必须放在 while 内，每轮重新计算。
 *
 * 四、本次易错点
 *
 * 1. 一开始把 mid 放在 while 外面，
 *    导致左右边界变化后 mid 没有更新。
 *
 * 2. 左闭右闭使用 while (left < right)，
 *    导致 left == right 时漏查最后一个元素。
 *
 * 3. 两种区间写法不能混用：
 *    左闭右闭：right = n-1，while(left <= right)。
 *    左闭右开：right = n，while(left < right)。
 *
 * 4. 左闭右开向左收缩时使用 right = mid，
 *    而不是 right = mid - 1。
 *
 * 5. nums[mid] 已经比较过，若不等于 target，
 *    更新边界时必须把 mid 排除。
 *
 * 五、复杂度分析
 *
 * 时间复杂度：O(log n)
 * 每次搜索都将候选区间缩小约一半。
 *
 * 空间复杂度：O(1)
 * 只使用 left、right、mid 等常数变量。
 *
 * 六、后续复盘
 *
 * - LC35：搜索插入位置
 * - LC34：查找第一个和最后一个位置
 * - lower_bound() / upper_bound()
 * - LC300：贪心 + 二分查找优化 LIS
 */


#include <vector>
using namespace std;

class Solution704 {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }

        int left = 0;
        int right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target < nums[mid]) {
                right = mid;
            }

            else if (target > nums[mid]) {
                left = mid + 1;
            }

            else {
                return mid;
            }
        }

        return -1;
    }
}; 
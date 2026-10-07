/*
 * LeetCode 26. Remove Duplicates from Sorted Array
 * 题目：删除有序数组中的重复项
 *
 * 核心：
 * 快慢指针 / 双下标
 *
 * 【读】fast：
 * 负责扫描数组，寻找新的不同元素。
 *
 * 【写】slow：
 * 指向下一个不重复元素应该写入的位置。
 *
 * 当 nums[fast] != nums[fast - 1] 时：
 *
 * nums[slow] = nums[fast];
 * slow++;
 *
 * 注意：
 * slow / fast 本质上是数组下标，并不是 C++ 真正的指针。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <vector>
using namespace std;

class Solution26 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        // slow--下一个元素写在哪里 第一个元素一定会保留，所以从1开始
        int slow = 1;

        // fast 负责顺着数组往后找
        for (int fast = 1; fast < n; fast++) {
            // 两个元素不重复 slow写入！
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
            
        }

        return slow;
    }
};
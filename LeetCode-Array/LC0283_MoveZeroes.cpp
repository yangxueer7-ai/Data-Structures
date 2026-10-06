/*
 * LeetCode 283. Move Zeroes
 * 题目：移动零
 *
 * 核心思路：
 * 双指针 / 双下标。
 *
 * fast：
 * 负责扫描整个数组，寻找非 0 元素。
 *
 * slow：
 * 指向下一个非 0 元素应该写入的位置。
 *
 * 第一阶段：
 * 遇到非 0 元素时：
 * nums[slow] = nums[fast];
 * slow++;
 * 这样可以把所有非 0 元素按原顺序移动到数组前面。
 *
 * 第二阶段：
 * 从 slow 开始到数组末尾全部补 0。
 *
 * 关键理解：
 * 不是“遇到 0 就往后搬”，
 * 而是“先把所有非 0 元素压到前面，
 * 剩下的位置自然全部填 0”。
 * fast 负责找非 0，slow 负责写非 0
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include<vector>

using namespace std;

class Solution283 {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int slow = 0;

        // 先筛选出所有非0元素 放到前面
        for (int fast = 0; fast < n; fast++) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
        }


        // 再依次把剩下位置补0
        for (int i = slow; i < n; i++) {
            nums[i] = 0;
        }

    }
};
/*
 * LeetCode 344. Reverse String
 * 题目：反转字符串
 *
 * 核心思路：
 * 左右双指针。
 *
 * left：
 * 从数组最左边开始。
 *
 * right：
 * 从数组最右边开始。
 *
 * 每一轮交换：
 *
 * swap(s[left], s[right]);
 *
 * 然后：
 * left++;
 * right--;
 * 当 left >= right 时停止。
 *
 * 为什么不用额外数组？
 *
 * 因为可以直接交换左右两端元素，
 * 原地完成反转。
 *
 * 注意：
 * 这里的 left / right 是数组下标，
 * 不是 C++ 真正的指针。
 *
 * 易错点：
 * 1. 循环条件应该是 left < right
 * 2. 不能遍历整个数组，否则会把已经交换好的元素再换回来
 * 3. 不能简单用 s[slow] = s[fast] 覆盖，否则原元素会丢失
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <vector>
using namespace std;

class Solution344 {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
/*
 * LeetCode 167. Two Sum II - Input Array Is Sorted
 * 题目：两数之和 II - 输入有序数组
 *
 * 核心思路：
 * 左右双指针。
 * 题目中的 numbers 已经按非递减顺序排列，
 * 因此可以利用“有序性”来缩小搜索范围。
 *
 * left：
 * 指向当前最左边候选元素。
 * right：
 * 指向当前最右边候选元素。
 *
 * 每一轮计算
 * sum = numbers[left] + numbers[right]
 *
 * 1. 如果 sum == target：
 *    找到答案。
 *
 * 2. 如果 sum < target：
 *    当前和太小，需要让和变大，
 *    所以 left++。
 *
 * 3. 如果 sum > target：
 *    当前和太大，需要让和变小，
 *    所以 right--。
 *
 * left 右移 -> 元素不会变小 -> 总和有机会变大
 * right 左移 -> 元素不会变大 -> 总和有机会变小
 *
 * 注意：
 *
 * C++ vector 的真实下标仍然是从 0 开始：
 *
 * numbers[0] ~ numbers[n - 1]
 *
 * 题目所谓“下标从 1 开始”，
 * 是指最终返回答案时要使用 1-based 编号。
 *
 * 因此找到答案后返回：
 *
 * {left + 1, right + 1}
 *
 * 易错点：
 * 1. 题目的 1-based 只影响返回值，不影响 C++ 数组访问。
 * 2. sum 太小时移动 left，sum 太大时移动 right。

 * 时间复杂度：O(n）
 * 空间复杂度：O(1）
 */

#include <vector>

using namespace std;

class Solution167 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return { left + 1, right + 1 };
            }

            if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};
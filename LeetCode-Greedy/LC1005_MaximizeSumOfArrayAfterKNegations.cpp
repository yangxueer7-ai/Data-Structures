/*
 * LeetCode 1005. Maximize Sum Of Array After K Negations
 * K 次取反后最大化的数组和
 *
 * 算法：贪心 + 排序 + 奇偶性判断
 *
 * 核心思路：
 * 1. 将数组按升序排序，使绝对值最大的负数优先被处理。
 * 2. 从左向右遍历，若当前元素为负数且 k > 0，
 *    则将其取反，并消耗一次操作。
 * 3. 遍历结束后，计算数组总和 sum 与最小绝对值 minAbs。
 * 4. 若剩余 k 为偶数，可反复翻转同一个元素，总和不变。
 * 5. 若剩余 k 为奇数，需要翻转绝对值最小的元素，
 *    因此最终总和减去 2 * minAbs。
 *
 * 关键边界：
 * 1. 如果 k 仍有剩余，说明所有负数都已被处理。
 * 2. 如果数组中仍有负数，则说明 k 已经用完。
 * 3. 若存在 0，剩余奇数次操作也不会影响总和。
 * 4. 需要减去 2 * minAbs，而不是 minAbs。
 *
 * 时间复杂度：O(n log n)，主要来自排序。
 * 空间复杂度：O(log n)，考虑 std::sort 的常见栈开销。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        // 升序排序，优先处理绝对值最大的负数
        sort(nums.begin(), nums.end());

        // 贪心：尽可能将负数变为正数
        // 如果k用完了，还有负数剩余
        // 如果k没用完跳出循环，说明nums里只有正数了
        for (int& x : nums) {
            if (x < 0 && k > 0) {
                x = -x;
                k--;
            }
        }

        int minAbs = INT_MAX;
        int sum = 0;

        // 计算数组总和与最小绝对值
        for (int x : nums) {
            minAbs = min(minAbs, abs(x));
            sum += x;
        }

        // 剩余奇数次操作：翻转绝对值最小的元素
        if (k % 2 == 1) {
            sum -= 2 * minAbs;
        }

        return sum;
    }
};
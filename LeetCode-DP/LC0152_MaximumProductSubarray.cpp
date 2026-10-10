
/*
 * ============================================================
 * LeetCode 152. 乘积最大子数组 (Maximum Product Subarray)
 * 难度：Medium
 * 专题：Dynamic Programming / 状态压缩 / 最大最小值
 *
 * 【核心思路】
 * 1. 求连续子数组的最大乘积，类似 LC53 最大子数组和。
 * 2. 由于负数乘负数可能变成正数，必须同时维护：
 *    maxVal：以当前位置结尾的最大连续子数组乘积。
 *    minVal：以当前位置结尾的最小连续子数组乘积。
 * 3. 当前元素可以独立开始，也可以接在之前的
 *    最大乘积或最小乘积后面。
 * 4. 使用 ans 维护所有位置中的全局最大乘积。
 *
 * 【状态转移】
 * x = nums[i];
 *
 * newMax = max({x, maxVal * x, minVal * x});
 * newMin = min({x, maxVal * x, minVal * x});
 *
 * maxVal = newMax;
 * minVal = newMin;
 * ans = max(ans, maxVal);
 *
 * 【初始化】
 * maxVal = nums[0];
 * minVal = nums[0];
 * ans = nums[0];
 *
 * 【空间压缩】⭐
 * 原本需要 maxDp[i] 和 minDp[i] 两个 DP 数组。
 * 由于当前状态只依赖上一位置的最大、最小乘积，
 * 因此可以使用两个变量，将空间压缩至 O(1)。
 *
 * 【易错点】
 * 1. 不能只维护最大乘积，负数可能使最小值变成最大值。
 * 2. 必须先计算 newMax、newMin，再更新 maxVal、minVal。
 *    否则新状态会覆盖旧状态，导致转移错误。
 * 3. ans 必须初始化为 nums[0]，不能默认初始化为 0。
 *    因为最大乘积也可能是负数。
 * 4. C++ 比较三个值，需要使用 max({a, b, c})。
 * 5. 遇到 0 时，当前乘积可以重新从后续元素开始。
 * 6. maxVal 是以当前位置结尾的最大乘积，
 *    ans 才是整个数组的最大乘积。
 *
 * 【复杂度】
 * 时间：O(n)，只遍历一次数组。
 * 空间：O(1)，仅使用常数个辅助变量。
 *
 * 【与 LC53 的区别】
 * LC53 最大子数组和：维护一个最大状态。
 * LC152 乘积最大子数组：同时维护最大和最小状态。
 *
 * 负负得正，最大最小同时维护；
 * 先算新状态，再覆盖旧状态。
 * ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution152 {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxVal = nums[0];
        int minVal = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int x = nums[i];

            int newMax = max({ x,maxVal * x,minVal * x });
            int newMin = min({ x,minVal * x,maxVal * x });

            maxVal = newMax;
            minVal = newMin;

            ans = max(ans, maxVal);
        }

        return ans;
    }
};
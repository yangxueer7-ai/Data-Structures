/*
 * LeetCode 238. 除自身以外数组的乘积
 * 难度：Medium
 * 专题：Array / Prefix Product / Suffix Product
 *
 * 核心思路：前缀积 + 后缀积
 *
 * 一、基本解法：两个辅助数组
 * 1. left[i] 表示 nums[i] 左侧所有元素的乘积。
 *    left[0] = 1;
 *    left[i] = left[i-1] * nums[i-1];
 *
 * 2. right[i] 表示 nums[i] 右侧所有元素的乘积。
 *    right[n-1] = 1;
 *    right[i] = right[i+1] * nums[i+1];
 *
 * 3. 最终答案：
 *    ans[i] = left[i] * right[i];
 *
 * 时间复杂度：O(n)
 * 额外空间复杂度：O(n)
 *
 * 二、空间优化：ans 数组 + suffix 滚动变量
 *
 * 1. 直接使用 ans 保存前缀积：
 *    ans[0] = 1;
 *    ans[i] = ans[i-1] * nums[i-1];
 *
 * 2. 使用 suffix = 1 维护当前位置右侧所有元素的乘积。
 *
 * 3. 从右往左遍历：
 *    ans[i] *= suffix;    // 前缀积 × 后缀积
 *    suffix *= nums[i];  // 更新后缀积，供下一轮使用
 *
 * 关键理解：
 * - ans[i] 原本保存当前位置左侧的乘积。
 * - suffix 保存当前位置右侧的乘积，不包含 nums[i]。
 * - 必须先更新 ans[i]，再更新 suffix！
 * - 如果先执行 suffix *= nums[i]，就会把当前元素乘进去。
 *
 * - 前缀积直接保存在输出数组 ans 中。
 * - 从右往左遍历时，后缀积可以逐步累乘。
 * - 因此不需要单独保存整个 right 数组。
 *
 * 易错点：
 * 1. 前缀积使用 nums[i-1]，不能包含 nums[i]。
 * 2. 后缀积使用 nums[i+1]，不能包含 nums[i]。
 * 3. 左右边界没有元素时，乘积初始化为 1。
 * 4. 从右往左遍历时，先 ans[i] *= suffix，
 *    再 suffix *= nums[i]，顺序不能交换。
 * 5. 本题不能使用除法，前后缀积也能正确处理 0。
 *
 * 优化后：
 * 时间复杂度：O(n)
 * 额外空间复杂度：O(1)，不计算输出数组 ans。
 */



#include <vector>
using namespace std;

class Solution238 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        vector<int> ans(n);

        // Prefix-前缀积
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }

        // Suffix-后缀积
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = left[i] * right[i];
        }

        return ans;
    }
};

class Solution238_update {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // 第一遍：ans 先保存每个位置左侧的乘积
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // 第二遍：用 suffix 维护当前位置右侧的乘积
        int suffix = 1;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;   // 左边乘积 × 右边乘积
            suffix *= nums[i]; // 更新后缀积，供下一轮使用
        }

        return ans;
    }
};
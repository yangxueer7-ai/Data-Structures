/*
 * LeetCode 525. 连续数组（Contiguous Array）
 *
 * 题型：前缀和 + 哈希表（最长连续子数组）
 * 核心思路：将 0 看作 -1、1 看作 +1，原题的「0 和 1 数量相等」
 *           等价于寻找「转换后元素和为 0」的最长连续子数组。
 *
 * 前缀和原理：
 *   prefix[r + 1] - prefix[l] = 0  <=>  prefix[r + 1] = prefix[l]
 *   即：两个位置的前缀和相同，它们之间的子数组和为 0。
 *
 * 哈希表定义：mp[sum] 表示前缀和 sum 第一次出现时的下标。
 * 1. 初始化 mp[0] = -1，表示还没有遍历元素时的空前缀。
 * 2. 遍历数组：遇到 0 时为 sum 加 -1；遇到 1 时为 sum 加 +1。
 * 3. 当前前缀和若是首次出现，就记录下标 i；否则保留更早的下标。
 * 4. 用 i - mp[sum] 计算满足条件的子数组长度，并更新最大值。
 *
 * 与 LC0560 的区别：
 *   LC0560 求子数组个数：记录每种前缀和出现的次数。
 *   LC0525 求最长子数组：记录每种前缀和最早出现的下标。
 *
 * 易错点：
 * - nums[i] == 0 ? -1 : 1; 这条语句不会修改 nums[i] 或 sum；
 *   必须写成 sum += (nums[i] == 0 ? -1 : 1)。
 * - 不能每轮都执行 mp[sum] = i，否则会覆盖最早位置。
 * - mp[0] = -1 是为了正确统计从下标 0 开始的合法子数组长度。
 *
 * 时间复杂度：平均 O(n)，每个元素只遍历一次，哈希操作平均 O(1)。
 * 空间复杂度：O(n)，哈希表最多记录 O(n) 种前缀和。
 */

#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;  // 前缀和 -> 第一次出现的下标
        int sum = 0;  
        int ans = 0; 

        mp[0] = -1;  // 空前缀：下标 -1 处的前缀和为 0

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            // 0 转成 -1，1 保持 +1；不修改原数组
            sum += (nums[i] == 0 ? -1 : 1);

            if (!mp.count(sum)) {
                mp[sum] = i;
            }

            ans = max(ans, i - mp[sum]);
        }

        return ans;
    }
};

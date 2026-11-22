/*
 * LeetCode 605. 种花问题（Can Place Flowers）
 * 难度：简单
 * 算法：贪心 + 一次遍历
 *
 * 【题意】
 * flowerbed[i] 为 0 表示空地，为 1 表示已种花。
 * 相邻位置不能同时种花，判断能否在不破坏规则的前提下再种 n 朵花。
 *
 * 【核心思路】
 * 从左往右扫描：如果当前空位的左邻居、右邻居都没有花，就立刻种花。
 * 每次种下后把 flowerbed[i] 修改为 1，这样后续位置会正确感知刚种的花。
 * 采用最早可种位置优先的贪心策略，不会比延后种植减少可种数量。
 *
 * 【边界处理】
 * - i == 0：左侧没有位置，视为满足左邻居为空的条件。
 * 
 * - i == m - 1：右侧没有位置，视为满足右邻居为空的条件。
 * 
 * - C++ 的 || 短路求值避免在边界访问 flowerbed[-1] 或 flowerbed[m]。
 * 
 * - 左右邻居都必须满足条件，因此只检查当前是否为 0 还不够。
 *
 * 【算法流程】
 * 1. 遍历花坛每个下标 i。
 * 2. 判断当前为空、左边为空或不存在、右边为空或不存在。
 * 3. 三个条件均满足时种花，计数加一。
 * 4. 最终判断新增数量 count 是否至少为 n。
 *
 * 【示例】
 * flowerbed = {0, 0, 1, 0, 0}, n = 2
 * 在下标 0 和 4 各种一朵，count = 2，返回 true。
 *
 * 【复杂度】
 * 时间：O(m)，其中 m 为 flowerbed 的长度，每个位置只访问一次。
 * 额外空间：O(1)，仅使用若干变量；算法会原地修改 flowerbed。
 *
 * 【AC 记录】2026-11-22，LeetCode 平台 AC。
 */

#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int m = static_cast<int>(flowerbed.size());
        int count = 0;

        for (int i = 0; i < m; i++) {
            bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
            bool rightEmpty = (i == m - 1 || flowerbed[i + 1] == 0);

            if (flowerbed[i] == 0 && leftEmpty && rightEmpty) {
                count++;
                flowerbed[i] = 1;
            }
        }

        return count >= n;
    }
};

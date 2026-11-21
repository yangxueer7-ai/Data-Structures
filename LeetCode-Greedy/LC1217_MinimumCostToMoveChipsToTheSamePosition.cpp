/*
 * LeetCode 1217. 玩筹码（Minimum Cost to Move Chips to The Same Position）
 * 难度：简单｜专题：贪心、奇偶性
 * 状态：2026-11-21 新题
 *
 * 【题意】
 * position[i] 表示第 i 个筹码的位置。把所有筹码移动到同一个位置：
 * 移动 2 个单位费用为 0，移动 1 个单位费用为 1，求最小总费用。
 *
 * 【核心思路】
 * 1. 两个位置的差为偶数时，可以反复移动 2 格，费用为 0；
 *    因此所有奇数位置可以免费互相移动，所有偶数位置也一样。
 * 2. 奇数位置与偶数位置之间至少需要一次 1 格移动，且一次就够。
 * 3. 若统一到奇数位置，只需为偶数位置的筹码付费；反之亦然。
 *    因此答案为 min(oddCount, evenCount)。
 *
 * 【易错点】
 * - 统计的是各奇偶位置上的“筹码数量”，不是不同位置的数量。
 * - 不需要排序，也不需要计算筹码之间的实际距离。
 *
 * 时间复杂度：O(n)，遍历一次 position。
 * 额外空间复杂度：O(1)，只使用两个计数器。
 *
 */

#include "LeetCodeCommon.h"

class Solution {
public:
    int minCostToMoveChips(std::vector<int>& position) {
        int oddCount = 0;
        int evenCount = 0;

        for (int x : position) {
            if (x % 2 == 0) {
                evenCount++;
            }
            else {
                oddCount++;
            }
        }

        return std::min(evenCount, oddCount);
    }
};

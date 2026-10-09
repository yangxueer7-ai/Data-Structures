
/*
 * ============================================================
 * LeetCode 45. 跳跃游戏 II (Jump Game II)
 * 难度：Medium
 * 专题：Greedy / 贪心 / BFS 分层思想
 *
 * 【核心思路】
 * 1. LC55 只判断能否到达终点，LC45 求最少跳跃次数。
 * 2. 将相同跳跃次数能够到达的位置看作 BFS 的一层。
 * 3. 扫描当前层，计算下一层能够覆盖的最远位置。
 * 4. 扫描到当前层边界时，跳跃次数 +1，并更新边界。
 *
 * 【变量含义】
 * jumps      ：已经确定的跳跃次数。
 * currentEnd ：当前跳跃次数能够到达的最右边界。
 * nextEnd    ：再跳一次能够到达的最右边界。
 *
 * 【贪心策略】
 * nextEnd = max(nextEnd, i + nums[i]);
 *
 * 当 i == currentEnd：
 * jumps++;
 * currentEnd = nextEnd;
 *
 * 【易错点】
 * 1. currentEnd 是当前层边界，不是实际落脚点。
 * 2. nextEnd 是下一层最远边界，不是下一跳的具体位置。
 * 3. 必须扫描完当前层，才能增加跳跃次数。
 * 4. 遍历条件为 i < n - 1，避免终点处多算一次。
 * 5. 题目保证终点可达，无需处理不可达情况。
 *
 * 【复杂度】
 * 时间：O(n)，每个下标最多扫描一次。
 * 空间：O(1)，只使用三个辅助变量。
 *
 * 贪心维护最远覆盖，BFS 思想按层计数；
 * currentEnd 负责结算，nextEnd 负责扩展。
 * ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution45 {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int jumps = 0;
        int currentEnd = 0;
        int nextEnd = 0;

        for (int i = 0; i < n - 1; i++) {
            nextEnd = max(nextEnd, i + nums[i]);

            if (i == currentEnd) {
                jumps++;
                currentEnd = nextEnd;
            }
        }

        return jumps;
    }
};

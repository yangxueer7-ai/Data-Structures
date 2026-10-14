/*
 * LeetCode 134. 加油站
 * 难度：Medium
 * 专题：Greedy 
 *
 * 核心思路：贪心 + 一次遍历
 *
 * 一、问题分析
 * gas[i] 表示第 i 个加油站可以获得的油量。
 * cost[i] 表示从第 i 站到下一站需要消耗的油量。
 *
 * 定义：
 * diff = gas[i] - cost[i];
 * diff > 0：当前站净赚油量。
 * diff < 0：当前站净亏油量。
 *
 * 二、核心变量
 *
 * total：整个环路的净油量之和。
 *        用于判断是否存在合法起点。
 *
 * cur：从当前候选起点 start 出发，
 *      到目前为止累计的净油量。
 *
 * start：当前候选起点的下标。
 *
 * 三、贪心过程
 *
 * 1. 遍历所有加油站，计算：
 *    diff = gas[i] - cost[i];
 *
 * 2. 累加：
 *    total += diff;
 *    cur += diff;
 *
 * 3. 如果 cur < 0：
 *    说明从当前 start 出发，无法通过站 i。
 *
 *    此时可以排除 start 到 i 之间的所有候选起点。更新：
 *    start = i + 1;
 *    cur = 0;
 *
 * 4. 遍历结束后：
 *    - total < 0：总油量不足，返回 -1。
 *    - total >= 0：返回 start。
 *
 * 四、贪心正确性
 *
 * 假设从 start 出发，第一次在站 i 处累计油量为负。
 * 那么从 start 到 i-1 的累计油量始终非负。
 * 如果改从这段区间内的某个站 j 出发，
 * 相当于舍弃了 start 到 j-1 积累的非负油量，
 * 因此也无法通过站 i。
 *
 * 所以可以直接跳过 start 到 i，
 * 将 i+1 作为新的候选起点。
 *
 * 五、本次易错点
 *
 * 1. 错误：cur = diff;
 *    正确：cur += diff;
 *
 *    cur 记录的是累计剩余油量，
 *    而不是当前单个加油站的净油量。
 *
 * 2. 错误：
 *    start = i + 1;
 *    cur = gas[start] - cost[start];
 *
 *    正确：
 *    start = i + 1;
 *    cur = 0;
 *
 *    原因：
 *    - 新起点尚未开始处理，应该从 0 重新累计。
 *    - 下一轮循环会自动加入新起点的 diff。
 *    - 提前访问 gas[start] 还可能导致数组越界。
 *
 * 3. total 和 cur 的区别：
 *    total 永远不清零，负责判断全局可行性。
 *    cur 失败后清零，负责寻找局部合法起点。
 *
 * 4. 判断失败必须使用 cur < 0，
 *    cur == 0 时仍然可以继续行驶。
 *
 * 六、复杂度分析
 *
 * 时间复杂度：O(n)
 * 只需遍历一次所有加油站。
 *
 * 空间复杂度：O(1)
 * 仅使用 total、cur、start 等常数变量。
 *
 * 七、与 LC435 无重叠区间的联系
 *
 * LC435：发生重叠时，保留右端点更小的区间。
 * LC134：当前起点失败时，排除一段不可能的起点。
 *
 * 两题的共同思想：
 * 利用贪心策略，一次性排除不可能的选择。
 */

#include <vector>

using namespace std;

class Solution134 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int total = 0;
        int start = 0;
        int cur = 0;

        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            cur += diff;

            if (cur < 0) {
                start = i + 1;
                cur = 0;
            }
        }

        if (total < 0) {
            return -1;
        }

        return start;
    }
};
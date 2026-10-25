/*
 * LeetCode 1710. 卡车上的最大单元数
 * Maximum Units on a Truck
 *
 * 【算法】排序 + 贪心（自定义 Lambda 比较器）
 *
 * 【题意】
 * boxTypes[i][0]：第 i 种箱子的数量
 * boxTypes[i][1]：第 i 种箱子中，每个箱子包含的单元数
 * truckSize：卡车最多能装的箱子数量（不是单元数）
 * 求最多能装载多少单元。
 *
 * 【核心思路】
 * 1. 每个箱子都占用一个箱位，因此优先选择“每箱单元数”更多的箱子。
 * 2. 按 boxTypes[i][1] 降序排序。第一个就是单元数最多的箱子，优先选择这个
 * 3. 从前往后遍历每种箱子：
 *       take = min(count, remaining)
 *       ans += take * units
 *       remaining -= take
 * 4. 卡车装满后可提前退出。
 *
 * 【贪心正确性】
 * 如果选了一个单元数较少的箱子，却留下了单元数较多的箱子，
 * 交换它们不会增加占用的箱位，却能使总单元数不减少。
 * 因此优先装单元数最多的箱子是最优选择。
 *
 * 【复杂度】
 * n 为箱子类型数：
 * 时间 O(n log n)，排序占主导；遍历 O(n)。
 * 额外空间取决于 std::sort 实现，常见实现使用 O(log n) 的递归栈。
 *
 * 【易错点】
 * - truckSize 限制的是“箱子个数”，不能直接把单元数与其比较！
 * - 每轮实际装入量是 min(count, remaining)，避免超出容量。
 */

#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // 1. 按每箱单元数（第二列）降序排列 自定义lambda比较器
        sort(boxTypes.begin(), boxTypes.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] > b[1];
            });

        int ans = 0;
        int remaining = truckSize;

        // 2. 按排序后的优先级依次装箱
        for (const auto& box : boxTypes) {
            int count = box[0]; 
            int units = box[1]; 

            // 3. 不能超过当前箱子数，也不能超过卡车剩余箱位 这里考虑到了count > truckSize的情况
            int take = min(count, remaining);

            ans += take * units; // 累加装载的单元数
            remaining -= take;   // 扣除已占用的箱位

            if (remaining == 0) {
                break; // 卡车已装满 跳出循环
            }
        }

        return ans;
    }
};

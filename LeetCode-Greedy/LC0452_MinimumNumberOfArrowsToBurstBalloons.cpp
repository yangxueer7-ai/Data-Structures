
/*
 * LeetCode 452. 用最少数量的箭引爆气球
 * 难度：Medium
 * 专题：Greedy / Sorting / Intervals
 *
 * 核心思路：按右端点升序排序 + 贪心选择射箭位置
 *
 * 一、贪心策略
 *
 * 1. 将所有气球按照右端点从小到大排序。
 * 2. 第一支箭射在第一个气球的右端点：
 *    end = points[0][1];
 *    ans = 1;
 * 3. 从第二个气球开始遍历：
 *    如果 points[i][0] <= end：
 *    说明当前气球包含射箭位置 end，
 *    可以继续使用已有的箭，不需要更新 end。
 *
 *    如果 points[i][0] > end：
 *    说明当前箭已经无法射中这个气球。
 *    此时新增一支箭,并更新end
 *
 * 二、为什么按照右端点排序？
 * 优先处理结束位置最早的气球。
 * 将箭放在它的右端点，既能射中当前气球，
 * 又尽可能为后续气球提供重叠机会。
 *
 * 如果当前箭还能射中后面的气球，
 * 就不需要移动射箭位置。
 *
 * 三、重要语法：Lambda 自定义排序
 * sort(points.begin(), points.end(),
 *     [](const vector<int>& a, const vector<int>& b) {
 *         return a[1] < b[1];
 *     }
 * );
 *
 * 语法解释：
 * - []：Lambda 捕获列表，此处不捕获外部变量。
 * - const vector<int>&：常量引用，避免复制区间。
 * - a[0]、b[0]：区间左端点。
 * - a[1]、b[1]：区间右端点。
 * - return a[1] < b[1]：按照右端点升序排序。
 *
 * 普通 sort(points.begin(), points.end())
 * 默认按字典序排序，即优先比较左端点。
 *
 * 四、与 LC435 无重叠区间对比
 *
 * LC435：
 * - 目标：移除最少的重叠区间。
 * - 本人的解法：按照左端点升序排序。
 * - 发生重叠时，保留右端点更小的区间。
 * - end = min(end, intervals[i][1]);
 *
 * LC452：
 * - 目标：使用最少的箭覆盖所有气球。
 * - 按照右端点升序排序。
 * - 当前箭能覆盖新气球时，保持 end 不变。
 * - 无法覆盖时，新增箭并更新 end。
 *
 * 共同思想：
 * 优先保留结束较早的选择，
 * 尽可能为后续区间留下空间。
 *
 * 六、复杂度分析
 *
 * 时间复杂度：O(n log n)
 * 主要来自 sort 排序，后续遍历为 O(n)。
 *
 * 额外空间复杂度：通常为 O(log n)
 * 取决于 std::sort 的具体实现。
 *
 * 右端点排序，箭射在最早结束的位置；
 * 能共用就共用，不能共用才新增箭。
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution452 {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            });

        int n = points.size();
        int ans = 1;
        int end = points[0][1];

        for (int i = 1; i < n; i++) {
            // 如果当前end连气球的左区间都到不了
            if (points[i][0] > end) {
                end = points[i][1];
                ans++;
            }
        }

        return ans;
    }
};

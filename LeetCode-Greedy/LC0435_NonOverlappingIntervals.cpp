/*
 * LeetCode 435. 无重叠区间
 * 难度：Medium
 * 专题：Greedy / Sorting / Intervals
 *
 * 核心思路：左端点排序 + 贪心维护最小右端点
 *
 * 1. 按照区间左端点升序排序。
 * 2. 使用 end 记录当前保留区间的右端点。
 * 3. 如果 intervals[i][0] >= end
      即当前扫描到的区间左端点都大于等于end，说明没重叠
      更新 end。
 * 4. 否则发生重叠：
 *    - 必须移除一个区间，ans++。
 *    - 保留右端点较小的区间：
 *      end = min(end, intervals[i][1])。
 *
 * 贪心思想：
 * 保留结束更早的区间，可以为后续区间留下更大空间。
 *
 * 易错点：
 * - 本题端点相接不算重叠。
 * - 重叠时不能直接保留当前区间。
 * - end 取 min，而 LC56 合并区间取 max。
 * - ans 统计的是删除数量
 *
 * 时间复杂度：O(n log n)，主要来自排序。
 * 额外空间复杂度：O(log n)，典型排序实现的栈空间。
 *
 * 左端点排序，遇到重叠就删一个，
 * 保留右端点更小的区间，为后续留下更多空间。
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution435 {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        // end变量用于维护区间右端点
        int end = intervals[0][1];
        int ans = 0;

        for (int i = 1; i < n; i++) {
            // 不重叠：保留当前区间，更新右端点
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
            }

            else {
                end = min(intervals[i][1], end);
                ans++;
            }
        }

        return ans;
    }
};
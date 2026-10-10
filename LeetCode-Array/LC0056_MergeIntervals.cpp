
/*
 * ============================================================
 * LeetCode 56. 合并区间 (Merge Intervals)
 * 难度：Medium
 * 专题：Array / Sorting 
 *
 * 【核心思路】
 * 1. 按区间左端点升序排序。
 * 2. 使用 ans 保存已经合并好的区间。
 * 3. 如果 ans 为空，直接加入当前区间。
 * 4. 如果当前区间左端点 <= ans 最后一个区间的右端点，
 *    说明两个区间重叠，需要合并。
 * 5. 如果不重叠，则将当前区间直接加入 ans。
 *
 * 【合并规则】
 * intervals[i][0] <= ans.back()[1]
 *
 * 合并后更新右端点：
 * ans.back()[1] = max(ans.back()[1], intervals[i][1]);
 *
 * 【二维 vector 操作】⭐
 * intervals[i]      ：第 i 个区间。
 * intervals[i][0]   ：第 i 个区间的左端点。
 * intervals[i][1]   ：第 i 个区间的右端点。
 *
 * ans.back()        ：ans 中最后一个区间。
 * ans.back()[0]     ：最后一个区间的左端点。
 * ans.back()[1]     ：最后一个区间的右端点。
 *
 * ans.push_back(intervals[i])：添加一个完整区间。
 *
 * 【易错点】
 * 1. 必须先排序，才能依次合并区间。
 * 2. 应与 ans.back() 比较，而不是简单比较 intervals[i-1]。
 *    因为前面的多个区间可能已经合并。
 * 3. 合并后的右端点必须取 max()，不能直接赋值，
 *    否则可能把 [1,10] 错误缩短为 [1,3]。
 * 4. ans 为空时不能调用 back()，应先加入第一个区间。
 * 5. 区间端点相等也算重叠，例如 [1,4] 和 [4,5]。
 * 6. 二维 vector 的第一个下标表示区间，第二个下标表示端点。
 *
 * 【复杂度】
 * 时间：O(n log n)，主要来自排序。
 * 空间：O(n)，结果数组最坏需要保存所有区间。
 *       排序的辅助空间取决于具体实现。
 *
 * 按左端点排序；
 * 重叠就扩展右边界，不重叠就新增区间。
 * ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution56 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++) {

            // 第一个区间直接加入ans
            if (ans.empty()) {
                ans.push_back(intervals[i]);
                continue;
            }

            // 当已合并的区间的右端点 大于等于当前区间的左端点
            // 说明两个区间重叠
            // 再次合并后的右端点取两者最大值
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {
                // 不重叠，加入一个新区间
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};


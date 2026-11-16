/*
 * LeetCode 0646. 最长数对链（Maximum Length of Pair Chain）
 * 难度：Medium
 * 算法：贪心 + 区间排序
 *
 * 【核心思路】
 * 数对 [a, b] 可以接在前一个数对后，当且仅当前一个数对的 右端点 lastEnd 严格小于 a。
 * 
 * 为了给后续数对留下尽可能多的空间，按右端点升序排序，
 * 优先选择结束最早的数对；之后只在 start > lastEnd 时选入。
 *
 * 【易错点】
 * - 条件必须是 start > lastEnd，不能写成 >=。
 * - 按右端点排序，不是按左端点排序。
 * - 已选第一个数对，count = 1，后续从下标 1 开始遍历。
 *
 * 时间复杂度：O(n log n)
 * 额外空间复杂度：O(log n)，来自 std::sort 的递归栈
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            });

        int lastEnd = pairs[0][1];
        int count = 1;

        for (int i = 1; i < static_cast<int>(pairs.size()); i++) {
            if (lastEnd < pairs[i][0]) {
                count++;
                lastEnd = pairs[i][1];
            }
        }

        return count;
    }
};

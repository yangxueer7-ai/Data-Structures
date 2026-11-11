/*
 * LC1208. 尽可能使字符串相等 (Get Equal Substrings Within Budget)
 *
 * 算法：可变长度滑动窗口 —— 费用约束型
 *
 * 思路：
 * 1. 将位置 i 的字符转换开销看作 abs(s[i] - t[i])。
 * 2. 右指针扩展窗口时，累加新位置的转换开销 curCost。
 * 3. 若 curCost > maxCost，则不断右移左指针，同时减去移出位置的开销，
 *    直到窗口的总转换开销重新满足预算限制。
 * 4. 每次窗口合法后，使用 right - left + 1 更新最长长度。
 *
 * 易错点：
 * - 每次收缩窗口时，必须同步减少 curCost。
 * - 使用 while 而不是 if，因为可能需要连续移除多个位置才能满足预算。
 * - maxCost == 0 时，仍可能存在转换开销为 0 的字符区间。
 *
 * 时间复杂度：O(n)，左右指针分别最多移动 n 次。
 * 空间复杂度：O(1)，只使用常数额外空间。
 */

#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int curCost = 0;
        int left = 0;
        int maxAns = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            curCost += abs(s[right] - t[right]);

            while (curCost > maxCost) {
                curCost -= abs(s[left] - t[left]);
                left++;
            }

            maxAns = max(maxAns, right - left + 1);
        }

        return maxAns;
    }
};

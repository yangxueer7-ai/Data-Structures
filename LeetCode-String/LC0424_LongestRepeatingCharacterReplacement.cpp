/*
 * LeetCode 424. 替换后的最长重复字符
 * 题型：滑动窗口 / 字符频次统计 / 贪心
 *
 * 思路：
 * 1. 用 cnt[26] 维护当前窗口各大写字母的出现次数。
 * 2. maxFreq 记录扫描过程中窗口字符频次达到过的最大值，只增不减。
 * 3. 当 窗口长度 - maxFreq > k 时，移动左端点收缩窗口。
 * 4. 更新窗口最大长度 ans。
 *
 * 易错点：
 * maxFreq 是历史最大频次，不一定等于当前窗口真实的最大频次。
 * 收缩时无需重新计算 maxFreq：某些当前窗口可能暂时不合法，
 * 但这种处理不会让最终记录的最长长度超过实际能够达到的长度。
 * 例如 s = "BABBAA", k = 1，答案为 4（合法窗口 "BABB"）。
 *
 * 时间复杂度：O(n)，两个指针均单调右移。
 * 空间复杂度：O(1)，字符频次数组大小固定为 26。
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int left = 0;
        int ans = 0;
        int maxFreq = 0;

        for (int right = 0; right < static_cast<int>(s.size()); right++) {
            cnt[s[right] - 'A']++;
            maxFreq = max(maxFreq, cnt[s[right] - 'A']);

            while (right - left + 1 - maxFreq > k) {
                cnt[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

/*
 * LeetCode 3. 无重复字符的最长子串
 * 难度：Medium
 * 专题：String / Sliding Window / Frequency Array
 *
 * 核心思路：
 * 1. 使用左右双指针维护一个无重复字符的滑动窗口。
 * 2. 使用 cnt[128] 记录 ASCII 字符在窗口中出现的次数。
 * 3. right 右移，cnt[s[right]]++，加入新字符。
 * 4. 如果 cnt[s[right]] > 1，说明新字符重复：
 *    不断移除 s[left]，并移动 left，直到窗口合法。
 * 5. 每次窗口合法后更新最大长度 ans。
 *
 * 易错点：
 * - 缩小窗口时，先 cnt[s[left]]--，再 left++。
 * - 使用 while 而非 if，因为可能需要多次缩小窗口。
 *
 * 时间复杂度：O(n)，每个字符最多进入和离开窗口一次。
 * 空间复杂度：O(1)，固定使用 128 个计数位置。

 * 右指针扩张，重复时左指针收缩，维护无重复窗口。
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> cnt(128, 0);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            cnt[s[right]]++;
            while(cnt[s[right]] > 1) {
                cnt[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
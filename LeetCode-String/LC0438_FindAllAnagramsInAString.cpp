/*
 * LeetCode 438. 找到字符串中所有字母异位词
 * 难度：Medium
 * 专题：String / Sliding Window / Frequency Array
 *
 * 核心思路：定长滑动窗口 + 字符频次数组
 *
 * 1. 使用 need[26] 统计字符串 p 中各字符出现的次数。
 * 2. 使用 window[26] 记录当前窗口内各字符的出现次数。
 * 3. right 向右移动，将 s[right] 加入窗口。
 * 4. 如果窗口长度超过 p.size()：
 *    - window[s[left] - 'a']--，移除左端字符。
 *    - left++，左边界右移。
 * 5. 当窗口长度等于 p.size() 且 window == need 时，
 *    说明当前窗口是 p 的字母异位词，记录 left。
 *
 * 重要语法：
 * - vector<int> cnt(26, 0)：创建长度为26、初始值为0的数组。
 * - s[i] - 'a'：将小写字母映射到 0~25 的数组下标。
 * - cnt[x]++ / cnt[x]--：增加或减少对应字符的出现次数。
 * - window == need：vector 支持逐元素比较。
 * - ans.push_back(left)：记录符合条件的起始下标。
 *
 * 易错点：
 * 1. ans 应初始化为空 vector<int> ans，而不是 ans(n,0)。
 * 2. need 和 window 要分开统计，不能混用。
 * 3. 窗口长度超过 m 才收缩，而不是字符不匹配就收缩。
 * 4. 先移除左端字符，再执行 left++。
 * 5. 只有窗口长度为 m 且频次完全相同时才记录答案。
 *
 * 与 LC3 对比：
 * - LC3：不定长窗口，重复时使用 while 收缩。
 * - LC438：定长窗口，超长时使用 if 收缩一次。
 *
 * 时间复杂度：O(n + m)，26 个字母的比较视为常数。
 * 空间复杂度：O(1)，两个固定长度为26的计数数组。
 *
 * 右指针加入新字符，窗口超长就移除左字符，
 * 保持定长并比较字符频次，相同则记录起点。
 */

#include <vector>
#include <string>

using namespace std;

class Solution438 {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<int> ans;
        // p中每个字符出现次数
        vector<int> need(26, 0);

        //s窗口的每个字符的出现次数
        vector<int> window(26, 0);

        int left = 0;
        for (int i = 0; i < m; i++) {
            // 将字符映射到下标，如果是b的话，映射到1，等等。。。
            need[p[i] - 'a']++;
        }

        for (int right = 0; right < n; right++) {
            window[s[right] - 'a']++;

            // 当窗口长度超过m时，收缩窗口！
            if (right - left + 1 > m) {
                window[s[left] - 'a']--;
                left++;
            }
                
            if (right - left + 1 == m && window == need) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};
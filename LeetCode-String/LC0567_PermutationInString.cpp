/*
 * LeetCode 567. 字符串的排列
 * 难度：Medium
 * 专题：String / Sliding Window / Frequency Array
 *
 * 核心思路：定长滑动窗口 + 字符频次数组
 *
 * 1. 状态定义：
 *    need[26]   记录 s1 中每个字符的出现次数。
 *    window[26] 记录 s2 当前窗口中每个字符的出现次数。
 *
 * 2. 初始化：
 *    m = s1.size()，n = s2.size()。
 *    如果 m > n，直接返回 false。
 *    遍历 s1，初始化 need 数组。
 *
 * 3. 滑动窗口：
 *    - right 右移，将 s2[right] 加入窗口。
 *    - 如果窗口长度超过 m，移除 s2[left]，left++。
 *    - 当窗口长度等于 m 时，比较 need 和 window。
 *    - 两个频次数组相同，说明找到 s1 的某种排列。
 *
 * 4. 返回结果：
 *    找到匹配窗口，立即 return true。
 *    遍历结束仍未找到，return false。
 *
 * 重要语法：
 * - vector<int> cnt(26, 0)：创建长度为26的计数数组。
 * - s[i] - 'a'：将小写字母映射到下标 0~25。
 * - cnt[x]++：对应字符进入窗口，频次加一。
 * - cnt[x]--：对应字符离开窗口，频次减一。
 * - need == window：vector 支持逐元素比较。
 *
 * 本次易错点：
 * 1. 不能直接写 need[s1[i]]++！
 *    因为字符 'a' 的 ASCII 编码为97，会导致数组越界。
 *    正确写法：need[s1[i] - 'a']++。
 *
 * 2. 不需要使用 reverse()！
 *    字母异位词只要求字符种类和出现次数相同，
 *    不要求字符顺序相同。
 *    reverse(need.begin(), need.end()) 会颠倒频次位置，
 *    并破坏 need 原本记录的字符统计信息。
 *
 * 3. 窗口长度必须固定为 m。
 *    超过 m 时移除左端字符，不能随意收缩。
 *
 * 4. 先 window[s2[left] - 'a']--，再 left++。
 *    否则可能移除错误的字符。
 *
 * 与 LC438 对比：
 * - LC438：找到所有匹配窗口，ans.push_back(left)。
 * - LC567：只需判断是否存在匹配，return true。
 * - 两题的定长滑动窗口模板完全相同。
 *
 * 时间复杂度：O(m+n)
 * 空间复杂度：O(1)，使用两个固定长度为26的数组。
 */

#include <string>
#include <vector>

using namespace std;

class Solution567 {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if (m > n) {
            return false;
        }

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        int left = 0;

        // ① 统计 s1 的字符频次
        for (int i = 0; i < m; i++) {
            need[s1[i] - 'a']++;
        }

        // ② 定长滑动窗口
        for (int right = 0; right < n; right++) {

            // 右边字符加入窗口
            window[s2[right] - 'a']++;

            // 如果窗口超过 m，移除左边字符
            if (right - left + 1 > m) {
                window[s2[left] - 'a']--;
                left++;
            }

            // ③ 窗口长度为 m 时，比较字符频次
            if (right - left + 1 == m && need == window) {
                return true;
            }
        }

        return false;
    }
};
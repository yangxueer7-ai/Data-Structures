/*
 * LeetCode 2516. 每种字符至少取 K 个
 * 难度：Medium
 * 算法：逆向思考 + 可变长度滑动窗口
 *
 * 【核心思路】
 * 每次只能从字符串两端取字符，因此最终剩下的字符
 * 必然形成一个连续子字符串。
 *
 * 原问题：从两端取走最少的字符
 * 转化为：在中间保留最长的合法连续子字符串
 *
 * 【窗口合法条件】
 * 每种字符至少取走 k 个，因此窗口内必须满足：
 *
 * window[c] <= total[c] - k
 *
 * 其中 total[c] 表示原字符串中字符 c 的总数量。
 *
 * 【实现步骤】
 * 1. 统计 a、b、c 的总数量，不足 k 则返回 -1。
 * 
 * 2. right 扩展窗口，增加当前字符频次。
 * 
 * 3. 如果当前字符频次超过允许保留的上限，
 *    则不断移动 left，直到窗口重新合法。
 * 
 * 4. 更新最长合法窗口 maxLen。
 * 5. 返回 n - maxLen。
 *
 * 【易错点】
 * 1. s[right] - 'a' 才是字符类型下标（0/1/2）。
 * 2. 判断条件必须使用 window[idx]，而非 s[right]。
 * 3. 只检查刚加入的字符即可，因为只有它可能超限。
 * 4. 最终返回 n - maxLen，而不是 maxLen。
 * 5. k = 0 时，所有字符均可保留，答案为 0。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> total(3, 0);
        vector<int> window(3, 0);

        for (char c : s) {
            total[c - 'a']++;
        }

        for (int i = 0; i < 3; i++) {
            if (total[i] < k) {
                return -1;
            }
        }

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            int idx = s[right] - 'a';
            window[idx]++;

            while (window[idx] > total[idx] - k) {
                window[s[left] - 'a']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return n - maxLen;
    }
};

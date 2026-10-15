/*
 * LeetCode 763. 划分字母区间 (Partition Labels)
 * 难度：Medium
 * 算法：贪心 / 区间划分
 *
 * 【题意】
 * 将字符串划分为尽可能多的片段，要求同一个字母
 * 最多只能出现在一个片段中，返回各片段的长度。
 *
 * 【核心思路】
 * 先记录每个字符最后一次出现的位置 last[]。
 * 再从左往右遍历，不断更新当前片段必须到达的最远右边界 end。
 * 当 i == end 时，说明当前片段中的所有字符都不会再出现在后面，
 * 此时立即划分，保证片段数量尽可能多。
 *
 * 【贪心过程】
 * 1. 第一次遍历：last[s[i]-'a'] = i，记录字符最后出现的位置。
 * 2. 第二次遍历：end = max(end, last[s[i]-'a'])。
 * 3. 当 i == end 时，当前片段可以结束：
 *    - ans.push_back(end - start + 1)，记录片段长度。
 *    - start = i + 1，更新下一个片段的起点。
 *
 * 【易错点】
 * 1. last[] 必须先预处理，不能直接使用初始化的 0。
 * 2. end 必须取 max，不能直接赋值，否则可能缩小右边界。
 * 3. ans 保存的是片段长度，不是结束下标！
 * 4. 下一段起点为 i + 1，而不是 i。
 * 5. 这里用 if (i == end)，不需要使用 while。
 *
 * 【复杂度】
 * 时间复杂度：O(n)，两次遍历字符串。
 * 空间复杂度：O(1)，固定大小的 26 个字母位置数组。
 * （不计算返回结果所占空间）
 *
 * 预处理字符最后位置，贪心维护最远右边界，
 * 扫描到边界就立即切分。
 */

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution763 {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        int start = 0;
        int end = 0;

        vector<int> last(26, 0);
        vector<int> ans;

        // 记录每个字符最后一次出现的位置
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }

        // 贪心划分区间
        for (int i = 0; i < n; i++) {
            end = max(end, last[s[i] - 'a']);

            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};
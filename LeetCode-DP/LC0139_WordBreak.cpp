
/*
 * LeetCode 139. 单词拆分
 * 难度：Medium
 * 专题：Dynamic Programming / Boolean DP
 *
 * 核心思路：一维布尔型 DP + 枚举字符串切割位置
 *
 * 一、状态定义
 * dp[i] 表示字符串 s 的前 i 个字符能否被
 * wordDict 中的单词成功拆分。
 *
 * dp[i] = true：存在至少一种合法拆分方案。
 * dp[i] = false：目前不存在合法拆分方案。
 *
 * 二、初始化
 * vector<bool> dp(n + 1, false);
 * dp[0] = true;
 *
 * 原因：
 * 空前缀不需要任何单词就可以完成拆分，
 * 同时作为后续状态转移的起点。
 *
 * 三、状态转移
 * 枚举前缀长度 i，以及切割位置 j（0 <= j < i）。
 * 将前 i 个字符分成两部分：
 * s[0 ... j-1]：前 j 个字符。
 * s[j ... i-1]：后面截取的子串。
 * 
 * 如果同时满足：
 * 1. dp[j] == true，前 j 个字符能够成功拆分。
 * 2. s.substr(j, i-j) 存在于 wordDict 中。
 *
 * 那么：
 * dp[i] = true;
 *
 * 只要存在一种合法切割方式，当前状态就成立。
 *
 * 四、重要 C++ 语法
 *
 * 1. 字符串截取：
 * string part = s.substr(j, i - j);
 * substr(起始下标, 截取长度)
 * 注意第二个参数是长度，不是结束下标！
 *
 * 2. 范围 for 循环：
 * for (const string& word : wordDict)
 * const：不修改字典中的字符串。
 * string&：使用引用，避免复制字符串。
 * word：当前遍历到的字典单词。
 *
 * 3. bool found = false;
 * 用于标记当前截取的子串是否存在于字典中。
 *
 * 五、本次易错点
 * 1. break 只退出所在的最内层循环。
 *    第一个 break：
 *    找到匹配单词后，退出 wordDict 遍历。
 *    第二个 break：
 *    确认 dp[i] = true 后，退出 j 循环。
 *    外层 i 循环仍然继续执行。
 *
 * 2. 为什么可以提前 break？
 *
 *    因为 dp[i] 只表示能否拆分，
 *    而不是统计所有拆分方案。
 *    一旦找到一种合法方案，
 *    dp[i] 就已经确定为 true，
 *    无须继续尝试其他切割位置。

 * 六、与其他 DP 题目对比
 *
 * LC91：统计解码方案数量，需要累加合法方案。
 * LC300：求最长递增子序列，需要不断取 max。
 * LC1143：求最长公共子序列，比较不同转移结果。
 * LC139：判断是否存在合法拆分，找到即可停止。
 
 * 七、复杂度分析
 *
 * 设 n 为 s 的长度，k 为字典单词数量。
 *
 * 时间复杂度：O(k * n^3)
 * 使用线性遍历字典查找单词，
 * 每次截取及字符串比较最坏需要 O(n)。
 *
 * 空间复杂度：O(n)
 * dp 数组占 O(n)，临时截取子串最多 O(n)。
 * 不计输入的 wordDict。
 * 后续优化：
 * 可使用 unordered_set 加速字典查询，
 * 并结合单词长度限制减少无效切割
 */

#include <vector>
#include <string>

using namespace std;

class Solution139 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            
            for (int j = 0; j < i; j++) {
                //前j个字符可以拆分
                if (dp[j] == true) {
                    //截取j开始 长度为i-j的子串
                    string part = s.substr(j, i - j);
                    bool found = false;

                    // 判断子串是否处于字典中
                    for (const string& word : wordDict) {
                        if (word == part) {
                            found = true;
                            break;
                        }
                    }

                    if (found) {
                        dp[i] = true;
                        break;
                    }
                }

            }
        }

        return dp[n];
    }
};

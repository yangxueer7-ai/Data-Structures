/*
 * LC1052. 爱生气的书店老板（Grumpy Bookstore Owner）
 *
 * 算法：固定长度滑动窗口 + 最大增益
 *
 * 核心思路：
 * 1. grumpy[i] == 0 时，顾客原本就满意，计入固定收益 base。
 * 
 * 2. 秘密技巧只能额外挽回 grumpy[i] == 1 时的顾客，
 *    因此用长度为 minutes 的窗口维护额外收益 curExtra。
 * 
 * 3. 右端进入窗口时，若老板生气则增加对应顾客数；
 *    窗口超过 minutes 时移除左端，并同步扣除其额外收益。
 * 
 * 4. 每当窗口长度恰好为 minutes，就更新 maxExtra。
 *    最终答案为 base + maxExtra。
 *
 * 易错点：
 * - 窗口维护的是“额外挽回”的顾客数，不是窗口内所有顾客数。
 * - 左端移出时，只需扣除原本因生气而不满意的顾客。
 * - maxExtra 保存遍历过的所有合法窗口的最大额外收益，
 *   而 curExtra 只表示当前窗口的收益。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int base = 0;
        int maxExtra = 0;
        int curExtra = 0;
        int n = customers.size();
        int left = 0;

        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                base += customers[i];
            }
        }

        for (int right = 0; right < n; right++) {
            if (grumpy[right] == 1) {
                curExtra += customers[right];
            }

            if (right - left + 1 > minutes) {
                if (grumpy[left] == 1) {
                    curExtra -= customers[left];
                }
                left++;
            }

            if (right - left + 1 == minutes) {
                maxExtra = max(maxExtra, curExtra);
            }
        }

        return maxExtra + base;
    }
};

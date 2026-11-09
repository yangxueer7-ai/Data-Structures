/*
 * LC1423. 可获得的最大点数
 *
 * 思路：固定长度滑动窗口 + 逆向思考
 * 1. 每次只能从两端取牌，取走 k 张后，剩下的 n-k 张牌必然连续。
 * 
 * 2. 取走的点数 = 数组总和 - 剩余窗口和；要使取走的点数最大，
 *    等价于寻找长度恰好为 n-k 的连续子数组的最小和。
 * 
 * 3. 右端加入新元素；窗口长度超过 n-k 时，移除最左侧元素。
 * 
 * 4. 窗口长度恰好为 n-k 时更新 minSum，不能漏掉第一个合法窗口。
 * 
 * 5. 当 k == n 时没有剩余的牌，直接返回数组总和。
 *
 * 时间复杂度：O(n)，空间复杂度：O(1)。
 * 易错点：窗口收缩与 minSum 更新是两个独立步骤；不能只在收缩时更新。
 */

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for (int x : cardPoints) {
            total += x;
        }

        if (k == n) {
            return total;
        }

        int left = 0;
        int minSum = INT_MAX;
        int curSum = 0;

        for (int right = 0; right < n; right++) {
            curSum += cardPoints[right];

            if (right - left + 1 > n - k) {
                curSum -= cardPoints[left];
                left++;
            }

            if (right - left + 1 == n - k) {
                minSum = min(minSum, curSum);
            }
        }

        return total - minSum;
    }
};

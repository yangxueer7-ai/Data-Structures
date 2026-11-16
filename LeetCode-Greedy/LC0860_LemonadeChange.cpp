/*
 * LeetCode 0860. 柠檬水找零（Lemonade Change）
 * 算法：贪心 + 模拟
 *
 * 【核心思路】
 * 每杯柠檬水售价 5 美元，顾客依次用 5、10、20 美元付款。
 * 维护手中 5 元和 10 元纸币数量：
 * 
 * 1. 收到 5 元：直接收下，不用找零。
 * 
 * 2. 收到 10 元：必须找一张 5 元，否则失败。
 * 
 * 3. 收到 20 元：优先找 10+5，尽量保留更灵活的 5 元纸币；
 *    如果做不到，再尝试用三张 5 元找零，否则失败。
 *
 * 【易错点】
 * - 不能只检查能否找零，还要及时扣减对应纸币数量。
 * - 找 20 元时必须同时有 10 元和 5 元，才能使用 10+5。
 * - 所有顾客都成功找零后，别忘记返回 true。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (int bill : bills) {
            if (bill == 5) {
                five++;
            }
            else if (bill == 10) {
                if (five == 0) {
                    return false;
                }
                five--;
                ten++;
            }
            else { // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};

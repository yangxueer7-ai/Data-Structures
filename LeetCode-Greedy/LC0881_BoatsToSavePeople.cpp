/*
 * LeetCode 881. 救生艇（Boats to Save People）
 * 算法：排序 + 贪心 + 双指针
 *
 * 【核心思路】
 * 1. 先对 people 按体重升序排序。
 * 2. left 指向最轻者，right 指向最重者。
 * 3. 优先安排最重的人：
 *    - 如果最轻者 + 最重者 <= limit：
 *      两人可以同船，left++、right--。去找寻其他的组合。
 *    - 否则：
 *      最重者只能单独乘船，right--。
 * 4. 无论如何，每轮都会使用一艘船，因此 ans++。
 *
 * 【贪心策略】
 * 优先处理最重的人。
 * 如果连最轻的人都无法与他配对，
 * 那么其他人也不可能与他配对。
 *
 * 【复杂度】
 * 时间：O(n log n)，主要来自排序。
 * 空间：双指针 O(1)，排序可能使用额外栈空间。
 *
 * 【易错点】
 * 1. 每艘船最多只能坐两个人。
 * 2. 无法配对时，不能移动 left。因为连最轻的人都无法与right配对，right指向的只可以单独坐船
 * 3. left <= right，最后一个人也需要船。
 * 4. 无论能否配对，每轮 ans 都加 1。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();

        int left = 0;
        int right = n - 1;
        int ans = 0;

        while (left <= right) {
            // 判断最重者与最轻者能否配对
            if (people[left] + people[right] <= limit) {
                left++;
                right--;
            }
            else {   // 若不能配对
                // 最重的单独一个船
                right--;
            }

            ans++; // 每轮都要使用一艘船
        }

        return ans;
    }
};


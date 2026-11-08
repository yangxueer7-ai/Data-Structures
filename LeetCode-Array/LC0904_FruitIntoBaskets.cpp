/*
 * LC0904. 水果成篮（Fruit Into Baskets）
 * 思路：可变长度滑动窗口 + unordered_map 维护水果出现频次。
 * 1. 右指针加入一个水果，mp[fruits[right]]++。
 * 2. 当窗口内水果种类超过 2 种（mp.size() > 2）时，持续收缩左边界。
 * 3. 左端水果频次减到 0 时，必须 erase 对应键，否则 mp.size() 不代表种类数。
 * 4. 窗口合法后用 max(ans, right - left + 1) 更新最长长度。
 * 易错点：mp[某种水果] 表示出现次数；mp.size() 才是水果种类数。
 *         这是求最长区间，不是统计个数，不能使用 ans += 窗口长度。
 * 复杂度：时间 O(n)（哈希表操作平均 O(1)），额外空间 O(1)（最多 3 种水果）。
 */

#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int ans = 0;
        int left = 0;

        for (int right = 0; right < fruits.size(); right++) {
            mp[fruits[right]]++;

            // 易错！当哈希表长度>2 即水果种类数>2 窗口不合法，需要收缩左边界
            while (mp.size() > 2) {
                mp[fruits[left]]--;

                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

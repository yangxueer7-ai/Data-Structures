/*
 * LeetCode 349. Intersection of Two Arrays
 * 两个数组的交集
 *
 * 算法：哈希集合 / unordered_set
 *
 * 核心思路：
 * 1. 使用 unordered_set 存储 nums1，自动去除重复元素。
 * 2. 遍历 nums2，判断当前元素是否存在于集合中。
 * 3. 如果存在，将该元素加入 ans。
 * 4. 随后执行 erase(x)，防止重复加入相同元素。
 *
 * 解法一：find() + erase()
 * - st.find(x) != st.end() 表示找到元素。
 * - st.erase(x) 删除已经处理过的元素。
 *
 * 解法二：count() + erase()
 * - st.count(x) > 0 表示集合中存在 x。
 * - 找到后加入答案，并删除对应元素。
 *
 * STL 知识点：
 * - unordered_set：哈希集合，元素唯一且无序。
 * - insert(x)：插入元素。
 * - find(x)：返回元素迭代器，失败则返回 end()。
 * - count(x)：返回元素出现次数，普通 set 中为 0 或 1。
 * - erase(x)：删除值为 x 的元素，返回删除数量。
 *
 * 时间复杂度：平均 O(n + m)
 * 空间复杂度：O(n + min(n,m))，包含答案数组
 *
 * 易错点：
 * 1. 交集元素只能出现一次。
 * 2. find() 返回迭代器，不是 bool。
 * 3. count() 返回出现次数，不是元素下标。
 * 4. unordered_set 不允许重复元素。
 * 5. erase(x) 不能直接删除 nums2 中的元素，
 *    它删除的是当前哈希集合中的元素。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution349 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end());
        vector<int> ans;

        for (int x : nums2) {
            // 找到了交集的元素，加入答案，并删除哈希集合中的该元素，防止重复加入
            if (st.count(x) > 0) {
                ans.push_back(x);
                st.erase(x);
            }
        }

        return ans;
    }
};
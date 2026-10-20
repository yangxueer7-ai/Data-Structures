/*
 * LeetCode 406. Queue Reconstruction by Height
 * 根据身高重建队列
 *
 * 算法：贪心 + 自定义排序 + vector 插入
 *
 * 核心思路：
 * 1. 身高降序排序；
      身高相同时，k 升序。
 * 2. 先安排高个子，再安排矮个子。
 * 3. 每个人按照 k 插入答案数组的对应位置。
 * 4. 后续矮个子的插入不会影响高个子的条件。
 *
 * STL 知识点：
 * - sort + Lambda：自定义排序
 * - const auto&：常量引用，避免复制
 * - vector::insert()：指定位置插入元素
 * - begin() + k：获取下标 k 对应的迭代器
 *
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(n)
 *
 * 易错点：
 * 1. 身高降序，k 升序，不能写反。
 * 2. person 是元素，不是下标。
 * 3. insert 插入的是整个 person，而不是 k。
 */

#include "LeetCodeCommon.h"

using namespace std;

class Solution406 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),
            [](const auto& a, const auto& b) {
                if (a[0] != b[0]) {
                    return a[0] > b[0];
                }

                return a[1] < b[1];
            });

        vector<vector<int>> ans;

        for (const auto& person : people) {
            // k为此人前面的人数，获取插入位置
            int k = person[1];

            ans.insert(ans.begin() + k, person);
        }

        return ans;

    }
};
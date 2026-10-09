
/*
 * ============================================================
 * LeetCode 11. 盛最多水的容器 (Container With Most Water)
 * 难度：Medium
 * 专题：Array / Two Pointers / Greedy
 *
 * 【核心思路】
 * 1. 左右双指针分别从数组两端向中间移动。
 * 2. 面积 = (right - left) * min(height[left], height[right])。
 * 3. 每次更新最大面积，然后移动较短的一边。
 *
 * 【贪心依据】
 * 宽度每次都会减小。
 * 如果移动较高的一边，较短边仍然限制水位，
 * 面积不可能超过当前面积。
 * 因此舍弃较短边，才有机会获得更大的面积。
 *
 * 【易错点】
 * 1. 面积高度取 min()，而不是 max()。
 * 2. 宽度为 right - left，不需要 +1。
 * 3. 两边高度相等时，任选一边移动即可。
 * 4. 必须先计算面积，再移动指针。
 *
 * 【复杂度】
 * 时间：O(n)，左右指针最多移动 n-1 次。
 * 空间：O(1)，只使用常数个辅助变量。
 *
 * 宽度必然缩小，舍弃短板才能寻找更优解。
 * ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution11 {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;

        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            ans = max(area, ans);

            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return ans;
    }
};

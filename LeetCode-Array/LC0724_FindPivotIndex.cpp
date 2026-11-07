/*
 * LeetCode 724. 寻找数组的中心下标（Find Pivot Index）
 *
 * 题型：前缀和 / 左右和维护
 * 核心思路：先计算数组总和 sum，再从左到右维护当前位置左侧的元素和 leftSum。
 *           当前位置的元素不属于左侧或右侧，因此：
 *           rightSum = sum - leftSum - nums[i]。
 *           如果 leftSum == rightSum，当前位置就是中心下标，立即返回 i。
 *
 * 易错点：
 * 1. 必须先判断左右和，再更新 leftSum += nums[i]；否则会把当前位置算进左侧。
 * 2. 寻找最左侧中心下标，按从左到右的顺序遍历，找到后直接返回。
 * 3. 无合法中心下标时返回 -1。
 *
 * 时间复杂度：O(n)，求总和和扫描中心下标各遍历一次。
 * 空间复杂度：O(1)，只使用固定数量的变量。
 */

#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;  
        int sum = 0;      

        for (int x : nums) {
            sum += x;
        }

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            // 当前元素不属于任何一侧
            int rightSum = sum - nums[i] - leftSum;
            if (rightSum == leftSum) {
                return i;  // 从左到右遍历，首次符合即最左中心下标
            }

            // 检查完当前位置，再将其纳入下一轮的左侧和
            leftSum += nums[i];
        }

        return -1;  
    }
};

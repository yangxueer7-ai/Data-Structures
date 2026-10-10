
/*
 * ============================================================
 * LeetCode 15. 三数之和 (3Sum)
 * 难度：Medium
 * 专题：Array / Sorting / Two Pointers
 *
 * 【核心思路】
 * 1. 先对 nums 升序排序。
 * 2. 固定第一个数 nums[k]，将三数之和转化为两数之和。
 * 3. 左指针 i = k + 1，右指针 j = n - 1。
 * 4. 根据 sum = nums[k] + nums[i] + nums[j] 移动指针。
 *
 * 【双指针规则】
 * sum < 0：i++，增大总和。
 * sum > 0：j--，减小总和。
 * sum == 0：记录答案，移动双指针并去重。
 *
 * 【三层去重】⭐ 核心难点
 *
 * ① 固定元素 k 去重：
 * if (k > 0 && nums[k] == nums[k - 1]) continue;
 *
 * 保留第一次出现的数值，跳过后续重复的 k。
 * 不能简单地和 nums[k + 1] 比较并跳过当前值，
 * 否则可能漏掉 [-1, -1, 2] 这样的合法三元组。
 *
 * ② 左指针 i 去重：
 * while (i < j && nums[i] == nums[i - 1]) i++;
 *
 * ③ 右指针 j 去重：
 * while (i < j && nums[j] == nums[j + 1]) j--;
 *
 * 【去重顺序】⭐
 * 找到合法答案后：
 * 1. ans.push_back({nums[k], nums[i], nums[j]});
 * 2. i++; j--;
 * 3. while 跳过左右两侧连续重复的元素。
 *
 * 必须先移动，再按上述条件去重！
 * 否则可能重复记录答案或陷入死循环。
 *
 * 【剪枝优化】
 * 如果 nums[k] > 0，则后面的数均为正数，
 * 三数之和不可能为 0，可以直接 break。
 *
 * 【易错点】
 * 1. 外层 k 去重使用 continue，不是 break。
 * 2. sum == 0 后不能直接结束，还要继续找其他答案。
 * 3. 找到答案后必须先 i++、j--，再去重。
 * 4. 连续重复元素使用 while，而不是 if。
 *
 * 【复杂度】
 * 时间：O(n^2)，排序后固定 k，内层双指针遍历。
 * 额外空间：双指针 O(1)，排序辅助空间依实现而定。
 * 不计结果数组。
 *
 * 排序固定一个数，左右双指针寻找另外两个数；
 * k 先去重，找到答案先移动，再对 i、j 去重。
 * ============================================================
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans;
        for (int k = 0; k < n - 2; k++) {
            if (nums[k] > 0) {
                break;
            }

            if (k > 0 && nums[k - 1] == nums[k]) {
                continue;
            }

            int i = k + 1;
            int j = n - 1;

            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];

                if (sum < 0) {
                    i++;
                }

                else if (sum > 0) {
                    j--;
                }

                else {
                    ans.push_back({ nums[k],nums[i],nums[j] });
                    i++;
                    j--;

                    while (i < j && nums[i] == nums[i - 1]) {
                        i++;
                    }

                    while (i < j && nums[j] == nums[j + 1]) {
                        j--;
                    }
                }
            }

        }

        return ans;
    }
};

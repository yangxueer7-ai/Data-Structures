/*
 * LeetCode 416. 分割等和子集 (Partition Equal Subset Sum)
 * 难度：Medium
 * 算法：动态规划 / 0-1 背包 / 布尔型 DP
 *
 * 【题意】
 * 给定一个只包含正整数的数组 nums，
 * 判断是否能将数组划分为两个元素和相等的子集。
 * 每个元素只能使用一次，子集不要求连续。
 *
 * 【核心思路】
 * 1. 先计算数组总和 sum。
 * 2. 若 sum 为奇数，不可能平分，直接返回 false。
 * 3. 若 sum 为偶数，将问题转化为：
 *    能否从 nums 中选出若干元素，使其和恰好为 sum/2？
 *
 * 本质是 0-1 背包的可行性问题：
 * 每个数字只有「选」和「不选」两种情况。
 *
 * 【DP 状态定义】
 * dp[i][j]：只考虑前 i 个数字，
 *           能否选出若干元素，使其和恰好为 j。
 *
 * 【状态转移】
 * 当前考虑的数字为 x = nums[i-1]。
 *
 * ① 不选当前数字：
 *    dp[i-1][j]
 *
 * ② 选当前数字（前提 j >= x）：
 *    dp[i-1][j-x]
 *
 * ③ 综合判断：
 *    dp[i][j] = dp[i-1][j] || dp[i-1][j-x]
 *
 * 只要「选」或「不选」有一种方案成立，
 * dp[i][j] 就为 true。
 *
 * 【初始化】
 * 创建 (n+1) × (target+1) 的二维 DP 数组，
 * 初始值全部为 false。
 *
 * dp[i][0] = true：
 * 无论考虑前几个数字，都能通过不选任何元素凑出 0。
 *
 * dp[0][j] = false（j > 0）：
 * 一个数字都不选，无法凑出正数。
 *
 * 【遍历顺序】
 * i 从 1 到 n，枚举当前考虑的数字。
 * j 从 1 到 target，枚举目标重量。
 *
 * 最终返回 dp[n][target]。
 *
 * 【易错点】
 * 1. target = sum/2，不是再除以 2。
 * 2. dp[i][j] 中 i 表示前 i 个数字，
 *    因此当前数字是 nums[i-1]。
 * 3. 初始化 dp[i][0] 时应包含 i=n，
 *    即 for(int i=0; i<=n; i++)。
 * 4. 不能直接用「选当前数字」的结果覆盖「不选」的结果。
 *    必须使用逻辑或 ||，保留所有可行方案。
 * 5. 选当前数字时使用 dp[i-1][j-x]，
 *    因为每个元素只能使用一次。

 * 【复杂度】
 * 设 target = sum/2。
 * 时间复杂度：O(n*target)
 * 空间复杂度：O(n*target)

 * 分割等和子集 → 寻找和为 sum/2 的子集；
 * 0-1 背包通过「选或不选」判断目标和是否可达。
 *
 * 【后续复习】
 * 1. 二维 DP 状态转移的独立推导。
 * 2. 一维 DP 空间优化。
 * 3. 为什么 0-1 背包的一维容量必须倒序遍历。
 
 *
 * 【一维 DP 状态定义】
 * dp[j]：使用当前已经处理过的元素，
 *        是否可以恰好凑出总和 j。
 *
 * dp[j] = true  ：可以凑出 j
 * dp[j] = false ：无法凑出 j
 *
 * 【初始化】
 * vector<bool> dp(target + 1, false);
 * dp[0] = true;
 *
 * 不选择任何元素时，可以凑出总和 0。
 * 其他总和在尚未处理元素时都无法凑出。
 *
 * 【状态转移】
 * 当前元素为 x，背包容量为 j。
 *
 * ① 不选当前元素 x：
 *    dp[j] 保持原来的状态。
 *
 * ② 选择当前元素 x：
 *    如果之前能够凑出 j-x，
 *    那么加上当前元素 x，就可以凑出 j。
 *
 * 因此：
 * dp[j] = dp[j] || dp[j-x];
 *
 * 其中：
 * dp[j]   ：不选择当前元素
 * dp[j-x] ：选择当前元素，检查剩余总和是否可达
 *
 * 【为什么必须倒序遍历？】
 * 二维 DP 的状态转移依赖上一行：
 *
 * dp[i][j] = dp[i-1][j] || dp[i-1][j-x]
 *
 * 压缩成一维后，需要确保 dp[j-x] 尚未在
 * 当前元素这一轮被更新。
 *
 * 因此容量 j 必须从 target 向 x 倒序遍历。
 *
 * 如果正序遍历，dp[j-x] 可能已经使用过当前元素，
 * 导致同一个元素被重复选择，变成完全背包。
 *
 * 【举例】
 * nums = [2]，target = 4
 *
 * 正序遍历：
 * dp[2] = true
 * dp[4] = dp[2] = true  // 错误！相当于使用了两次 2
 *
 * 倒序遍历：
 * 先计算 dp[4]，此时 dp[2] 仍为 false。
 * 再计算 dp[2]，由 dp[0] 得到 true。
 *
 * 因此 dp[4] 保持 false，符合每个元素只能使用一次的要求。
 *
 * 【与二维 DP 对比】
 *
 * 二维：
 * dp[i][j]：前 i 个元素能否凑出 j
 * 空间复杂度 O(n * target)
 *
 * 一维：
 * dp[j]：当前已经处理过的元素能否凑出 j
 * 空间复杂度 O(target)
 *
 * 核心优化：用倒序更新保护上一轮状态。


 *  j >= x
 *    当前容量必须能够容纳当前元素。
 *    同时避免访问负数下标。
 *
 * 【易错点】
 * 1. sum 为奇数时必须提前返回 false。
 * 2. dp[0] 必须初始化为 true。
 * 3. 数组长度必须为 target+1，才能访问 dp[target]。
 * 4. 一维 0-1 背包的容量必须倒序遍历。
 * 5. 状态转移使用逻辑或 ||，不能只保留选择当前元素的方案。
 * 6. 最终返回 dp[target]，不需要额外寻找 best。
 
 */

#include <vector>

using namespace std;

class Solution1D {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int x : nums) {
            sum += x;
        }

        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int x : nums) {
            for (int j = target; j >= x; j--) {
                dp[j] = dp[j] || dp[j - x];
            }
        }

        return dp[target];
    }
};

class Solution416_2D {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int x : nums) {
            sum += x;
        }

        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        vector<vector<bool>> dp(
            n + 1, vector<bool>(target + 1, false)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];

            for (int j = 1; j <= target; j++) {
                // 不选当前元素
                dp[i][j] = dp[i - 1][j];

                // 选当前元素
                if (j >= x) {
                    dp[i][j] =
                        dp[i][j] || dp[i - 1][j - x];
                }
            }
        }

        return dp[n][target];
    }
};




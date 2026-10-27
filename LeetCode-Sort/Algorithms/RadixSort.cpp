/*
 * LSD Radix Sort（最低有效位优先的基数排序）
 *
 * 适用范围：非负整数数组，按十进制从小到大排序。
 * 核心思想：依次按照个位、十位、百位……进行稳定的分配与收集。
 *
 * 1. 提取当前数位 digit = (x / exp) % 10。
 * 2. 将原始数字 x 放入 buckets[digit]，桶内保留原有相对顺序。
 * 3. 按桶 0～9 的顺序收集，写回 nums。
 * 4. 一整轮结束后 exp *= 10，处理下一数位。
 *
 * 时间复杂度：O(d * (n + 10))，d 为最大元素的十进制位数。
 * 辅助空间复杂度：O(n + 10)，用于十个桶及其保存的元素。
 * 稳定性：稳定（同一桶内的元素按进入顺序写回）。
 *
 * 注意：本实现不直接支持负数；若需要处理负数，应额外设计符号处理。
 */

#include <algorithm>
#include <vector>
using namespace std;

void radixSort(vector<int>& nums) {
    if (nums.empty()) return;

    int maxVal = *max_element(nums.begin(), nums.end());
    long long exp = 1; // 当前数位：1=个位、10=十位、100=百位……

    while (maxVal / exp > 0) {
        // 每一轮重新建立空桶，不能沿用上一轮的元素。
        vector<vector<int>> buckets(10);

        // 1. 分配：按当前数位放入对应的桶，保存的是原数字 x。
        for (int x : nums) {
            int digit = static_cast<int>((x / exp) % 10);
            buckets[digit].push_back(x);
        }

        // 2. 收集：桶间按数位升序，桶内按原有顺序。
        int index = 0;
        for (int i = 0; i < 10; ++i) {
            for (int x : buckets[i]) {
                nums[index] = x;
                ++index;
            }
        }

        // 当前数位处理完毕，进入下一数位。
        exp *= 10;
    }
}

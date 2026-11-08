#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // 平均值 >= threshold 等价于窗口元素和 >= k * threshold
        int target = k * threshold;
        int left = 0;
        int sum = 0;
        int ans = 0;

        for (int right = 0; right < arr.size(); right++) {
            // 右端元素进入窗口
            sum += arr[right];

            // 固定窗口长度为 k：超过 k 就移除最左端元素
            if (right - left + 1 > k) {
                sum -= arr[left];
                left++;
            }

            // 窗口恰好有 k 个元素时，判断是否达到平均值要求
            if (right - left + 1 == k && sum >= target) {
                ans++;
            }
        }

        return ans;
    }
};

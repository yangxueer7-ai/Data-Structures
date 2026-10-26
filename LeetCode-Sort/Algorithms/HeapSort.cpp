#include <algorithm>
#include <vector>
using namespace std;

/*
 * 算法名称：堆排序（Heap Sort）
 * 排序目标：升序（使用大根堆）
 *
 * 【核心思想】
 * 1. 将数组视为从下标 0 开始存储的完全二叉树：
 *    左孩子下标 2*i+1；右孩子下标 2*i+2。
 * 2. 自底向上建大根堆，保证每个父结点的值不小于其孩子。
 * 3. 交换堆顶 nums[0] 与当前堆尾 nums[end]，把最大值放到最终位置。
 * 4. 将有效堆大小缩小到 end，从根结点重新下沉调整。
 *
 * 【heapify 的含义】
 * 在左右子树已经是大根堆的前提下，以 i 为根进行向下调整。
 * heapSize 是堆中有效元素数量，有效下标 [0, heapSize)，不包含已排序后缀。
 * largest 是父结点 i 和两个孩子中，当前最大元素的下标。
 * 如果发生交换，原父结点移动到了 largest，需要继续调整该子树。
 *
 * 【408 性质】
 * 建堆时间：O(n)
 * 总时间（最好/平均/最坏）：O(n log n)
 * 辅助空间：此递归下沉版本最坏 O(log n)（递归栈）；迭代下沉可 O(1)
 * 稳定性：不稳定
 * 数组调整：原地（不另开 O(n) 辅助数组）
 *
 * 【易错点】
 * 1. 最后一个非叶结点下标是 n/2-1，不是 n/2+1。
 * 2. 判断孩子是否在堆内必须用 child < heapSize，而不是 <=。
 * 3. 交换堆顶与堆尾之后，heapify(nums, end, 0)：堆大小是 end。
 * 4. 下沉应沿交换后的孩子下标 largest 继续，不能简单 i++。
 */

 // 让以 i 为根的子树恢复大根堆性质（左右子树须已是大根堆）
void heapify(vector<int>& nums, int heapSize, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && nums[left] > nums[largest]) {
        largest = left;
    }
    if (right < heapSize && nums[right] > nums[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = nums[i];
        nums[i] = nums[largest];
        nums[largest] = temp;

        heapify(nums, heapSize, largest);
    }
}

void heapSort(vector<int>& nums) {
    int n = static_cast<int>(nums.size());

    // 1. 从最后一个非叶结点开始，自底向上建大根堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(nums, n, i);
    }

    // 2. 依次把最大值交换到右侧有序区
    for (int end = n - 1; end > 0; end--) {
        swap(nums[0], nums[end]);
        // nums[end] 已就位，剩余有效堆区间为 [0, end)
        heapify(nums, end, 0);
    }
}

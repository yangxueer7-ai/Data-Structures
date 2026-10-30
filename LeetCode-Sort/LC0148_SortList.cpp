/*
 * LeetCode 0148 - Sort List（排序链表）
 *
 * 方法：自顶向下归并排序（快慢指针拆分 + 合并两个有序链表）
 *
 * 思路：
 * 1. 空链表或单节点直接返回。
 * 2. slow 从 head 开始，fast 从 head->next 开始，找到左半段的尾节点。
 * slow每次走一步，fast每次走两步，直到 fast到达链表末尾，slow刚好在中间，分开两个链表
 * 3. 保存 slow->next 作为右半段头节点，再令 slow->next = nullptr 真正断开。
 * 4. 递归排序左右链表，最后用 dummy + tail 原地合并。
 *
 * 易错点：
 * - 判断 fast 和 fast->next 是否都存在，必须使用 &&，避免空指针解引用。
 * - 链表移动使用 p = p->next，不能使用 p++。
 * - 链表头节点和函数返回值是 ListNode*，不是 int。
 * - 合并完成后接上剩余链表，返回 dummy.next，而不是 tail。
 * - left->val <= right->val 时优先选左侧，使归并稳定。
 *
 * 时间复杂度：O(n log n)
 * 额外空间复杂度：O(log n)（递归栈；链表节点原地链接，合并本身 O(1)）
 * 稳定性：稳定。
 *
 * LeetCode 已提供 ListNode 定义，这里不重复定义。
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rightNode = slow->next;
        slow->next = nullptr;

        ListNode* leftPart = sortList(head);
        ListNode* rightPart = sortList(rightNode);
        return mergeTwoLists(leftPart, rightPart);
    }

    // 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            }
            else {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        tail->next = (left != nullptr) ? left : right;
        return dummy.next;
    }
};

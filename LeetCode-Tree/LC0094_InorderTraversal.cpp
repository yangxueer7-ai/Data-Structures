/*
 * ============================================================
 * LeetCode 94 - 二叉树的中序遍历
 * Binary Tree Inorder Traversal
 * ============================================================
 *
 * 【题目要求】
 * 给定二叉树根节点 root，返回其中序遍历结果。
 *
 * 【遍历顺序】
 * 左子树 -> 根节点 -> 右子树
 *
 * 【本题实现】
 * 使用栈 stack<TreeNode*> 模拟递归调用栈，完成迭代中序遍历。
 *
 * 【核心思路】
 * 1. 当前节点不为空：
 *      - 当前节点入栈
 *      - 继续向左子树移动
 *
 * 2. 当前节点为空：
 *      - 说明左边已经走到底
 *      - 从栈顶取出之前保存的节点
 *      - 访问该节点
 *      - 转向它的右子树
 *
 * 【循环条件】
 * root != nullptr || !stk.empty()
 *
 * 只有：
 * root == nullptr && stk.empty()
 * 才说明整棵树遍历结束。
 *
 * 【易错点】
 * 1. 入栈 != 访问节点
 * 2. ans.push_back(root->val) 才是真正的“访问”
 * 3. 中序遍历必须先处理左子树，再访问根节点
 * 4. stack 的 pop() 不返回元素，需要先 top() 再 pop()
 *
 * 【复杂度】
 * 时间复杂度：O(n)
 * 空间复杂度：O(h)，最坏 O(n)
 *
 * 【测试树】
 *
 *      1
 *       \
 *        2
 *       /
 *      3
 *
 * 【期望输出】
 * 1 3 2
 * ============================================================
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ==================== 二叉树节点定义 ====================
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// ==================== 中序遍历 ====================
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> stk;

    while (root != nullptr || !stk.empty()) {
        
        // ① 能往左就一直往左
        // 当前节点先保存到栈中，等待之后访问
        if (root != nullptr) {
            stk.push(root);
            root = root->left;
        }


        // ② 若左边走到底了
        // 回到最近一个尚未访问的节点
        else {
            root = stk.top();
            stk.pop();

            ans.push_back(root->val);
            // 访问根节点后转向他的右子树
            root = root->right;
        }
    }

    return ans;
}

// ==================== 测试 ====================
int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = inorderTraversal(root);

    for (int x : result) {
        cout << x << endl;
    }

    return 0;
}
/*
 * ============================================================
 * LeetCode 102 - 二叉树的层序遍历
 * Binary Tree Level Order Traversal
 * ============================================================
 *
 * 【题目要求】
 * 给定二叉树根节点 root，按照从上到下、从左到右的顺序，
 * 返回每一层节点的值。
 *
 * 【本题实现】
 * 使用队列 queue 进行 BFS
 *
 * 【核心思路】
 * queue 中保存接下来需要访问的节点。
 *
 * 每轮 while 开始时：
 *
 *      int size = q.size();
 *
 * 此时 queue 中的节点正好属于当前层，
 * 因此使用 size 固定当前层需要处理的节点数量。
 *
 * 对当前层的每个节点：
 * 1. 取出队头节点并访问
 * 2. 将节点值加入 level
 * 3. 左孩子非空 -> 入队
 * 4. 右孩子非空 -> 入队
 *
 * 当前层处理完成后：
 *
 *      ans.push_back(level);
 *
 * 此时 queue 中剩下的正好是下一层节点。
 *
 * 【为什么要保存 size？】
 * for 循环过程中会不断把下一层节点加入 queue，
 * 因此 q.size() 会动态变化。
 *
 * 先保存：
 *      int size = q.size();
 *
 * 才能保证本轮 for 只处理“当前层”的节点。
 *
 * 【易错点】
 * 1. 空树要直接返回空 ans
 * 2. size 必须在处理当前层之前保存
 * 3. level 每进入新的一层都要重新创建
 * 4. 左右孩子非空时才入队
 * 5. 不需要区分层时，普通 BFS 不一定需要 size；
 *    需要按层处理时才需要 size
 *
 * 【复杂度】
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 *
 * 【测试树】
 *
 *          3
 *        /   \
 *       9     20
 *            /  \
 *           15   7
 *
 * 【期望输出】
 * [[3], [9,20], [15,7]]
 * ============================================================
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// ====================
// BFS Level Order
// ====================

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;

    if (root == nullptr) {
        return ans;
    }

    q.push(root);

    while (!q.empty()) {

        // 保存当前层节点数量
        int size = q.size();

        vector<int> level;

        for (int i = 0; i < size; i++) {

            TreeNode* cur = q.front();
            q.pop();

            // 访问当前节点
            level.push_back(cur->val);

            // 下一层节点入队
            if (cur->left != nullptr) {
                q.push(cur->left);
            }

            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }

        // 当前层处理结束
        ans.push_back(level);
    }

    return ans;
}


int main() {

    /*
     * 构造测试树：
     *
     *          3
     *        /   \
     *       9     20
     *            /  \
     *           15   7
     */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = levelOrder(root);


    cout << "Level Order Traversal:" << endl;

    for (const vector<int>& level : result) {

        for (int value : level) {
            cout << value << " ";
        }

        cout << endl;
    }

    // 释放动态申请的内存
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
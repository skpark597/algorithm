/* 102. Binary Tree Level Order Traversal */
/** Given the root of a binary tree, return the level order traversal of its nodes' values. 
 *  (i.e., from left to right, level by level).
 * 
 *  Example 1:
 *  Input: root = [3,9,20,null,null,15,7]
 *  Output: [[3],[9,20],[15,7]]
 * 
 *  Example 2:
 *  Input: root = [1]
 *  Output: [[1]]
 * 
 *  Example 3:
 *  Input: root = []
 *  Output: []
 * 
 *  Constraints:
 *  The number of nodes in the tree is in the range [0, 2000].
 *  -1000 <= Node.val <= 1000 **/

#include "TreeNode.h"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> answer;
    queue<TreeNode *> queue;

    if (root == nullptr) return answer;

    queue.push(root);
    while (!queue.empty()) {
        int size = queue.size();
        vector<int> newLevel(size, 0);
        
        for (int i = 0; i < size; ++i) {
            TreeNode *cur = queue.front();
            queue.pop();
            newLevel[i] = cur->val;

            if (cur->left != nullptr) {
                queue.push(cur->left);
            }

            if (cur->right != nullptr) {
                queue.push(cur->right);
            }
        }
        answer.push_back(newLevel);
    }

    return answer;
}

int main() {
    TreeNode *node07 = new TreeNode(7);
    TreeNode *node015 = new TreeNode(15);
    TreeNode *node020 = new TreeNode(20, node015, node07);
    TreeNode *node09 = new TreeNode(9);
    TreeNode *node03 = new TreeNode(3, node09, node020);

    vector<vector<int>> ans0 = levelOrder(node03);
    for (vector<int> iter0 : ans0) {
        cout << "[";
        for (int iter1 : iter0) {
            cout << iter1 << " ";
        }
        cout << "]";
    } cout << endl; // [[3],[9,20],[15,7]]

    return 0;
}
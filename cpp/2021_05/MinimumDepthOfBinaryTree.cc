/** 111. Minimum Depth of Binary Tree */
/** Given a binary tree, find its minimum depth.
 *  The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 * 
 *  Note: A leaf is a node with no children.
 * 
 *  Example 1:
 *  Input: root = [3,9,20,null,null,15,7]
 *  Output: 2
 * 
 *  Example 2:
 *  Input: root = [2,null,3,null,4,null,5,null,6]
 *  Output: 5
 * 
 *  Constraints:
 *  The number of nodes in the tree is in the range [0, 10^5].
 *  -1000 <= Node.val <= 1000 **/

#include <vector>
#include <queue>
#include <limits.h>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 아래는 DFS
int minDepth(TreeNode *root) {
    if (root == nullptr) return 0;

    int minHeight = INT_MAX;

    if (root->left != nullptr)  minHeight = minDepth(root->left);
    if (root->right != nullptr) minHeight = min(minHeight, minDepth(root->right));

    return minHeight == INT_MAX ? 1 : minHeight+1;
}

// 아래는 BFS
int minDepth2(TreeNode *root) {
    if (root == nullptr) return 0;

    queue<TreeNode *> queue;
    int minDepth = 0;
    queue.push(root);

    while (!queue.empty()) {
        int size = queue.size();
        minDepth++;

        for (int i = 0; i < size; ++i) {
            TreeNode *cur = queue.front();
            bool hasLeft = cur->left != nullptr;
            bool hasRight = cur->right != nullptr;

            queue.pop();
            
            if (!hasLeft && !hasRight) return minDepth;
            if (hasLeft) queue.push(cur->left);
            if (hasRight) queue.push(cur->right);
        }
    }
    
    return minDepth;
}

int main() {
    // no test case
    return 0;
}


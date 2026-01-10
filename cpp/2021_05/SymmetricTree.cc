/** 101. Symmetric Tree */
/** Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
 * 
 *  Example 1:
 *  Input: root = [1,2,2,3,4,4,3]
 *  Output: true
 * 
 *  Example 2:
 *  Input: root = [1,2,2,null,3,null,3]
 *  Output: false
 * 
 *  Constraints:
 *  The number of nodes in the tree is in the range [1, 1000].
 *  -100 <= Node.val <= 100 */

#include "TreeNode.h"
#include "limits.h"
#include <iostream>
#include <queue>

const int NONE = INT_MAX;

bool isSymmetric(TreeNode *root) {
    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
        int size = queue.size();
        vector<int> values(size);

        for (int i = 0; i < size; ++i) {
            TreeNode *cur = queue.front();
            queue.pop();
            values[i] = cur == nullptr ? NONE : cur->val;

            if (cur != nullptr) {
                queue.push(cur->left);
                queue.push(cur->right);
            }
        }

        for (int i = 0; i < size/2; ++i) {
            if (values[i] != values[size-i-1]) return false;
        }
    }

    return true;
}

int main() {
    TreeNode *root0 = util::makeTree({1,2,2,3,4,4,3});
    TreeNode *root1 = util::makeTree({1,2,2,NONE,3,NONE,3});

    bool ans0 = isSymmetric(root0);
    bool ans1 = isSymmetric(root1);

    cout << ans0 << endl; // true
    cout << ans1 << endl; // false

    return 0;
}
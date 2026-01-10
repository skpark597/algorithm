/* 337. House Robber III */
/** The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.
 *  Besides the root, each house has one and only one parent house. 
 *  After a tour, the smart thief realized that all houses in this place form a binary tree. 
 *  It will automatically contact the police if two directly-linked houses were broken into on the same night.
 *  
 *  Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
 * 
 *  Example 1:
 *  Input: root = [3,2,3,null,3,null,1]
 *  Output: 7
 *  Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * 
 *  Example 2:
 *  Input: root = [3,4,5,1,3,null,1]
 *  Output: 9
 *  Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 * 
 *  Constraints:
 *  The number of nodes in the tree is in the range [1, 10^4].
 *  0 <= Node.val <= 10^4 **/

#include "TreeNode.h"
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<TreeNode *, int> cache;

int maxAmount (TreeNode *root, bool parentIsRobbed) {
    int cand1 = 0;
    int cand2 = 0;

    if (root == nullptr) return 0;
    if (!parentIsRobbed) {
        if (cache.count(root) != 0) {
            cand1 = cache[root];
        } else {
            cache[root] = root->val + maxAmount(root->left, true) + maxAmount(root->right, true);
            cand1 = cache[root];
        }
    }

    cand2 = maxAmount(root->left, false) + maxAmount(root->right, false); 
    return max(cand1, cand2);
}

int rob(TreeNode *root) {
    return maxAmount(root, false);
}

int main() {
    TreeNode *node03 = new TreeNode(3);
    TreeNode *node01 = new TreeNode(1);
    TreeNode *node02 = new TreeNode(2, nullptr, node03);
    TreeNode *node03_2 = new TreeNode(3, nullptr, node01);
    TreeNode *node03_3 = new TreeNode(3, node02, node03_2);

    TreeNode *node11 = new TreeNode(1);
    TreeNode *node13 = new TreeNode(3);
    TreeNode *node14 = new TreeNode(4, node11, node13);
    TreeNode *node15 = new TreeNode(5, nullptr, node11);
    TreeNode *node13_2 = new TreeNode(3, node14, node15);

    int ans0 = rob(node03_3);
    cache.clear();

    int ans1 = rob(node13_2);

    cout << ans0 << endl; // 7
    cout << ans1 << endl; // 9

    return 0;
}
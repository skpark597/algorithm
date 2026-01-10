/* 450. Delete Node in a BST */
/** Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
 *  Return the root node reference (possibly updated) of the BST.
 *  Basically, the deletion can be divided into two stages:
 * 
 *  Search for a node to remove.
 *  If the node is found, delete the node.
 *  Follow up: Can you solve it with time complexity O(height of tree)?
 * 
 *  Example 1:
 *  Input: root = [5,3,6,2,4,null,7], key = 3
 *  Output: [5,4,6,2,null,null,7]
 *  Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
 *  One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
 *  Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
 * 
 *  Example 2:
 *  Input: root = [5,3,6,2,4,null,7], key = 0
 *  Output: [5,3,6,2,4,null,7]
 *  Explanation: The tree does not contain a node with value = 0.
 * 
 *  Example 3:
 *  Input: root = [], key = 0
 *  Output: []
 * 
 *  Constraints:
 *  The number of nodes in the tree is in the range [0, 10^4].
 *  -10^5 <= Node.val <= 10^5
 *  Each node has a unique value.
 *  root is a valid binary search tree.
 *  -10^5 <= key <= 10^5  **/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *deleteLeastUpperBound(TreeNode *root, int &data) {
    if (root->left == nullptr) {
        data = root->val;
        return root->right;
    } else {
        root->left = deleteLeastUpperBound(root->left, data);
    }
    
    return root;
}

TreeNode *deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;

    if (root->val == key) {
        if (root->left ==  nullptr && root->right ==  nullptr) return nullptr; 
        else if (root->left == nullptr) return root->right;
        else if (root->right == nullptr) return root->left;
        else {
            root->right = deleteLeastUpperBound (root->right, root->val);
        }
    } else if (root->val > key) {
        root->left = deleteNode (root->left, key);
    } else if (root->val < key) {
        root->right = deleteNode (root->right, key);
    }

    return root;
}

int main () {
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node3 = new TreeNode(3, node2, node4);
    TreeNode *node6 = new TreeNode(6,nullptr,node7);
    TreeNode *node5 = new TreeNode(5,node3, node6);

    TreeNode *answer = deleteNode(node5,0);

    return 0;
}
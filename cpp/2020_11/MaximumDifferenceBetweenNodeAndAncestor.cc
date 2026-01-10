/* 1026. Maximum Difference Between Node and Ancestor */
/** Given the root of a binary tree, find the maximum value V for which there exist different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.
 *  A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.
 * 
 *  Example 1:
 *  Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
 *  Output: 7
 *  Explanation: We have various ancestor-node differences, some of which are given below :
 *  |8 - 3| = 5 |3 - 7| = 4 |8 - 1| = 7 |10 - 13| = 3
 *  Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
 * 
 *  Example 2:
 *  Input: root = [1,null,2,null,0,3]
 *  Output: 3
 *  
 *  Constraints:
 *  The number of nodes in the tree is in the range [2, 5000].
 *  0 <= Node.val <= 10^5 **/

#include <vector>
#include <map>
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

map<TreeNode *, int> maximums;
map<TreeNode *, int> minimums;

void setMinMaxOfTrees (TreeNode *root) {
    int minimum = root->val;
    int maximum = root->val;
    TreeNode *left = root->left;
    TreeNode *right = root->right;

    if (left != nullptr) {
        setMinMaxOfTrees(left);
        minimum = min(minimum, minimums[left]);
        maximum = max(maximum, maximums[left]);
    }
    
    if (right != nullptr) {
        setMinMaxOfTrees(right);
        minimum = min(minimum, minimums[right]);
        maximum = max(maximum, maximums[right]);
    }

    minimums[root] = minimum;
    maximums[root] = maximum;
}

int maximumDifference (TreeNode *root) {
    int diff = max(maximums[root]- root->val, root->val - minimums[root]);
    TreeNode *left = root->left;
    TreeNode *right = root->right;

    if (left != nullptr) {
        diff = max(diff, maximumDifference(left));
    }

    if (right != nullptr) {
        diff = max(diff, maximumDifference(right));
    }

    return diff;
}

int maxAncestorDiff (TreeNode *root) {
    if (root == nullptr) return 0;
    setMinMaxOfTrees(root);
    return maximumDifference(root);
}

int main() {
    //TreeNode *node3 = new TreeNode(3);
    //TreeNode *node0 = new TreeNode(0, node3, nullptr);
    //TreeNode *node2 = new TreeNode(2, nullptr, node0);
    //TreeNode *node1 = new TreeNode(1, nullptr, node2);

    TreeNode *node13 = new TreeNode(13);
    TreeNode *node14 = new TreeNode(14, node13, nullptr);
    TreeNode *node10 = new TreeNode(10, nullptr, node14);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node6 = new TreeNode(6, node4, node7);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node3 = new TreeNode(3, node1, node6);
    TreeNode *node8 = new TreeNode(8,node3,node10);

    int answer = maxAncestorDiff(node8);
    cout << answer << endl;

    return 0;
}





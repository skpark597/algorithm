/* 687. Longest Univalue Path */
/** Given the root of a binary tree, return the length of the longest path, 
 *  where each node in the path has the same value. This path may or may not pass through the root.
 *  The length of the path between two nodes is represented by the number of edges between them.
 * 
 *  Example 1:
 *  Input: root = [5,4,5,1,1,5]
 *  Output: 2
 *  
 *  Example 2:
 *  Input: root = [1,4,5,4,4,5]
 *  Output: 2
 * 
 * Constraints:
 *  The number of nodes in the tree is in the range [0, 10^4].
 *  -1000 <= Node.val <= 1000
 *  The depth of the tree will not exceed 1000. **/

/* 1205와 같은 문제. Discussion을 보고 효율 좋은 방법으로 재구현. 근데 원래 내 방법이랑 비슷한듯 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ret;

int helper(TreeNode *node, int val) {
    if (node == nullptr) return 0;

    if (node->val != val) {
        helper(node, node->val);
        return 0;
    }

    int left = helper(node->left, val);
    int right = helper(node->right, val);
    ret = max(ret, left + right);
    
    return max(left, right) + 1;
}

int longestUnivaluePath(TreeNode* root) {
    if (root == nullptr) return 0;

    ret = 0;
    helper(root, root->val);
    return ret;
}

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node1_2 = new TreeNode(1);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node4 = new TreeNode(4, node1, node1_2);
    TreeNode *node5_2 = new TreeNode(5, nullptr, node5);
    TreeNode *node5_3 = new TreeNode(5,node4, node5_2);

    TreeNode *nnode4 = new TreeNode(4);
    TreeNode *nnode4_2 = new TreeNode(4);
    TreeNode *nnode4_3 = new TreeNode(4, nnode4, nnode4_2);
    TreeNode *nnode5 = new TreeNode(5);
    TreeNode *nnode5_2 = new TreeNode(5, nullptr, nnode5);
    TreeNode *nnode1 = new TreeNode(1, nnode4_3, nnode5_2);

    TreeNode *nnnode1 = new TreeNode(1);
    TreeNode *nnnode1_2 = new TreeNode(1, nnnode1, nullptr);

    TreeNode *n2 = new TreeNode(2);
    TreeNode *n2_2 = new TreeNode(2);
    TreeNode *n2_3 = new TreeNode(2, n2, n2_2);
    TreeNode *n2_4 = new TreeNode(2);
    TreeNode *n1 = new TreeNode(1, n2_3, n2_4);

    TreeNode *m1 = new TreeNode(1);
    TreeNode *m2 = new TreeNode(1);
    TreeNode *m3 = new TreeNode(1);
    TreeNode *m4 = new TreeNode(1, m1, m2);
    TreeNode *m5 = new TreeNode(1, m3, nullptr);
    TreeNode *m6 = new TreeNode(1, m4, m5);
    TreeNode *m7 = new TreeNode(1, nullptr, m6);

    int answer = longestUnivaluePath(node5_3); // 2
    int answer2 = longestUnivaluePath(nnode4_3); // 2
    int answer3 = longestUnivaluePath(nnnode1_2); // 1
    int answer4 = longestUnivaluePath(n1); // 2
    int answer5 = longestUnivaluePath(m7); // 4

    cout << answer << endl;
    cout << answer2 << endl;
    cout << answer3 << endl;
    cout << answer4 << endl;
    cout << answer5 << endl;

    return 0;
}



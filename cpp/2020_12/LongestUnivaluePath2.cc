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

/* 내가 처음 생각한 솔루션. Accepted 되었으나 효율은 안좋은 편 */

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

map<int, int> lengths;

int setLengths(TreeNode *node) {
    TreeNode *left;
    TreeNode *right;
    bool leftSame;
    bool rightSame;
    int length = 0;
    int leftLength = 0;
    int rightLength = 0;
    int result = 0;

    if (node == nullptr) return 0;

    left = node->left;
    right = node->right;
    leftSame = (left != nullptr) && (left->val == node->val);
    rightSame = (right != nullptr) && (right->val == node->val);
    leftLength = setLengths(left);
    rightLength = setLengths(right);

    if (leftSame && rightSame) {
        length = leftLength + rightLength + 2;
        result = max(leftLength, rightLength) + 1;
    } else if (leftSame) {
        length = leftLength + 1;
        result = leftLength + 1;
    } else if (rightSame) {
        length = rightLength + 1;
        result = rightLength + 1;
    }

    if (lengths.count(node->val)) {
        lengths[node->val] = max(lengths[node->val], length);
    } else {
        lengths[node->val] = length;
    }

    return result;
}

int longestUnivaluePath(TreeNode* root) {
    int answer = 0;

    lengths.clear();
    setLengths(root);

    for (auto iter = lengths.begin(); iter != lengths.end(); ++iter) {
        answer = max(iter->second, answer);
    }

    return answer;
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
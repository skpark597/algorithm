/* 129. Sum Root to Leaf Numbers */
/** You are given the root of a binary tree containing digits from 0 to 9 only.
 *  Each root-to-leaf path in the tree represents a number.
 *  For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
 *  Return the total sum of all root-to-leaf numbers.
 * 
 *  A leaf node is a node with no children.
 * 
 *  Example 1:
 *  Input: root = [1,2,3]
 *  Output: 25
 *  Explanation:
 *  The root-to-leaf path 1->2 represents the number 12.
 *  The root-to-leaf path 1->3 represents the number 13.
 *  Therefore, sum = 12 + 13 = 25.
 * 
 *  Example 2:
 *  Input: root = [4,9,0,5,1]
 *  Output: 1026
 *  Explanation:
 *  The root-to-leaf path 4->9->5 represents the number 495.
 *  The root-to-leaf path 4->9->1 represents the number 491.
 *  The root-to-leaf path 4->0 represents the number 40.
 *  Therefore, sum = 495 + 491 + 40 = 1026.
 * 
 *  Constraints:
 *  The number of nodes in the tree is in the range [1, 1000].
 *  0 <= Node.val <= 9
 *  The depth of the tree will not exceed 10. **/

#include "/home/seungkyun/Algorithm/LeetCode/common/TreeNode.h"
//#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> dfs(TreeNode *node, int &sum) {
    vector<int> heights;

    if (node == nullptr) return heights;

    if (node->left == nullptr && node->right == nullptr) {
        sum += node->val;
        heights.push_back(0);
    }

    for (int iter : dfs(node->left, sum)) {
        sum += pow(10, iter+1) * node->val;
        heights.push_back(iter+1);
    }

    for (int iter : dfs(node->right, sum)) {
        sum += pow(10, iter+1) * node->val;
        heights.push_back(iter+1);
    }
    
    return heights;
}

int sumNumbers(TreeNode *root) {
    int answer = 0;
    dfs(root, answer);

    return answer;
}

int main() {
    TreeNode *node02 = new TreeNode(2);
    TreeNode *node03 = new TreeNode(3);
    TreeNode *node01 = new TreeNode(1, node02, node03);

    TreeNode *node11 = new TreeNode(1);
    TreeNode *node15 = new TreeNode(5);
    TreeNode *node19 = new TreeNode(9, node15, node11);
    TreeNode *node10 = new TreeNode(0);
    TreeNode *node14 = new TreeNode(4, node19, node10);

    int ans0 = sumNumbers(node01);
    int ans1 = sumNumbers(node14);

    cout << ans0 << endl; // 25
    cout << ans1 << endl; // 1026

    return 0;
}




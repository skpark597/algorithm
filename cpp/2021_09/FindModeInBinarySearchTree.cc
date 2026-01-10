/** 501. Find Mode in Binary Search Tree **/
/** Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
 *  If the tree has more than one mode, return them in any order.
 * 
 *  Assume a BST is defined as follows:
 *  The left subtree of a node contains only nodes with keys less than or equal to the node's key.
 *  The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
 *  Both the left and right subtrees must also be binary search trees.
 * 
 *  Example 1:
 *  Input: root = [1,null,2,2]
 *  Output: [2]
 * 
 *  Example 2:
 *  Input: root = [0]
 *  Output: [0]
 *  
 *  Constraints:
 *  The number of nodes in the tree is in the range [1, 10^4].
 *  -10^5 <= Node.val <= 10^5
 *  
 *  Follow up: Could you do that without using any extra space? 
 *  (Assume that the implicit stack space incurred due to recursion does not count).**/

#include <vector>
#include <iostream>
#include <unordered_map>
#include "TreeNode.h"

using namespace std;

unordered_map<int,int> numToCount;
int maxCount;

void setCount(int val) {
    if (numToCount.count(val) != 0) {
        numToCount[val]++;
    } else {
        numToCount[val] = 1;
    }
    
    maxCount = max(maxCount, numToCount[val]);
}

void dfs(TreeNode *root) {
    if (root == nullptr) return;
    setCount(root->val);

    dfs(root->left);
    dfs(root->right);
}

vector<int> findMode(TreeNode* root) {
    vector<int> answer;
    numToCount.clear();
    maxCount = 0;

    dfs(root);

    for (const auto& iter : numToCount) {
        if (iter.second == maxCount) answer.push_back(iter.first);
    }

    return answer;
}

int main() {
    TreeNode *root0 = util::makeTree({1,NONE, 2,2});
    vector<int> ans0 = findMode(root0);

    TreeNode *root1 = util::makeTree({0});
    vector<int> ans1 = findMode(root1);

    for (int iter : ans0) cout << iter <<" ";
    cout << endl;

    for (int iter : ans1) cout << iter <<" ";
    cout << endl;

    return 0;
}
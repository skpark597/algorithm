/* 105. Construct Binary Tree from Preorder and Inorder Traversal */
/** Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and 
 *  inorder is the inorder traversal of the same tree, construct and return the binary tree.
 *  
 *  Example 1:
 *  Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 *  Output: [3,9,20,null,null,15,7]
 * 
 *  Example 2:
 *  Input: preorder = [-1], inorder = [-1]
 *  Output: [-1]
 * 
 *  Constraints:
 *  1 <= preorder.length <= 3000
 *  inorder.length == preorder.length
 *  -3000 <= preorder[i], inorder[i] <= 3000
 *  preorder and inorder consist of unique values.
 *  Each value of inorder also appears in preorder.
 *  preorder is guaranteed to be the preorder traversal of the tree.
 *  inorder is guaranteed to be the inorder traversal of the tree. **/

#include "/home/seungkyun/Algorithm/LeetCode/common/TreeNode.h"
#include <vector>

using namespace std;

vector<int> pre;
vector<int> in;

TreeNode* buildTreeInternal(int pStart, int pEnd, int iStart, int iEnd) {
    TreeNode *cur;
    int leftCount = 0;

    if (pStart > pEnd) return nullptr;
    cur = new TreeNode(pre[pStart]);

    for (leftCount; leftCount <= iEnd-iStart; ++leftCount) {
        if (pre[pStart] == in[iStart+leftCount]) break;
    }

    cur->left = buildTreeInternal(pStart+1, pStart+leftCount, iStart, iStart+leftCount-1);
    cur->right = buildTreeInternal(pStart+leftCount+1, pEnd, iStart+leftCount+1, iEnd);

    return cur;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
    pre.clear();
    in.clear();
    pre = preorder;
    in = inorder;

    return buildTreeInternal(0, preorder.size()-1, 0, inorder.size()-1);
}

int main() {
    vector<int> preorder0 = {3,9,20,15,7};
    vector<int> inorder0 = {9,3,15,20,7};

    vector<int> preorder1 = {-1};
    vector<int> inorder1 = {-1};

    vector<int> preorder2 = {1,2};
    vector<int> inorder2 = {1,2};

    vector<int> preorder3 = {1,2,3};
    vector<int> inorder3 = {3,2,1};


    TreeNode *ans0 = buildTree(preorder0, inorder0);
    TreeNode *ans1 = buildTree(preorder1, inorder1);
    TreeNode *ans2 = buildTree(preorder2, inorder2);
    TreeNode *ans3 = buildTree(preorder3, inorder3);

    return 0;
}
